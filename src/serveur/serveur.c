/******************************************************************************/
/*			Application: ....			              */
/******************************************************************************/
/*									      */
/*			 programme  SERVEUR 				      */
/*									      */
/******************************************************************************/
/*									      */
/*		Auteurs :  ....						      */
/*		Date :  ....						      */
/*									      */
/******************************************************************************/

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#include <sys/signal.h>
#include <sys/wait.h>

#include <reseau/fon.h>		/* Primitives de la boite a outils */
#include <reseau/protocole.h>	/* Types pour la communication client <-> serveur */

#include <common.h>
#include <donnees/bdd.h>
#include "traitement.h"
#include "serveur.h"
#include <gestion/gestionadherents.h>
#include <gestion/gestionlivres.h>
#include <ctype.h>
#include <unistd.h>
void serveur_appli (char *service, char *protocole);	/* programme serveur */

//static char port_courant[PORT_LMAX] = PORT_DEFAUT;
//static char protocole_courant[PROTOCOL_LMAX] = PROTOCOLE_DEFAUT;
prot_params_t prot_params;

dbfiles files_conf;
/*------------------------------------------------------------------*/
/* SERVEUR															*/
/*------------------------------------------------------------------*/

void
serveur_doc_syntaxe (char *progname)
{
  fprintf (stderr, "Usage : %s [-p port] [-t] [-a filename] [-d filename]\n"
	   "-p port: utiliser le port p plutot que " PORT_DEFAUT "\n"
	   "-t utiliser TPC plutot que UDP\n"
	   "-a utiliser un fichier annuaire différent que celui par défaut\n"
	   "-d utiliser un ficher caatalogue différent que celui par défaut.\n",progname);
}

/*------------------------------------------------------------------*/
void
traitement_serveur ()
{
  //Socket file descriptor.
  int sockfd;
  //sockaddr serveur
  struct sockaddr_in sa;
  char hostname[26];
  //On récupère le hostname
  gethostname (hostname, 25);

  //Socket client file descriptor
  int clientfd;
  struct sockaddr_in addr_client;

  //Pour récupérer les opérations
  prot_requete_t rqt_client;
  prot_reponse_t rep_client;
  //Pour le fork()
  int pid_fils;

  livre_t livres_results[RESULT_LMAX];
  //Si on fait du tcp...
  if (prot_params.type == sock_tcp)
    {
      //Création de la socket serveur
      sockfd = h_socket (AF_INET, SOCK_STREAM);
      //Renseignement des adresses de la socket
      adr_socket (prot_params.port, hostname, "tcp", &sa, SERVEUR);
      //Association...
      h_bind (sockfd, &sa);
      //On passe en mode écoute
      h_listen (sockfd, 10);
      while (1)
	{
	  clientfd = h_accept (sockfd, &addr_client);
	  pid_fils = fork ();
	  if (pid_fils == 0)
	    {
	      while (h_reads
		     (clientfd, (char *) (&rqt_client),
		      sizeof (rqt_client)) > 0)
		{
		  int i;
		  printf ("Recu operation de type : %c \n",
			  rqt_client.operation);
		  switch (rqt_client.operation)
		    {
		    case (op_consulter_auteur):

		      rep_client.code =
			trait_consulter_auteur (files_conf.fichierCatalogue,rqt_client.param,
						livres_results);
		      rep_client.livres = (livre_t*) livres_results;

		      for (i = 0; i < LIVRES_NBMAX; i++)
			{
			  afficher_livre (livres_results[i]);
			}
		      break;
		    case (op_consulter_titre):
		      rep_client.code =
			trait_consulter_titre (files_conf.fichierCatalogue,rqt_client.param,
					       livres_results);
		      rep_client.livres = (livre_t*) livres_results;

		      for (i = 0; i < LIVRES_NBMAX; i++)
			{
			  afficher_livre (livres_results[i]);
			}
		      break;
		    case (op_ping):
		      rep_client.code=ret_pong;
		    default:
		      rep_client.code = ret_operation_impossible;
		      break;
		    }
		  h_writes (clientfd, (char *) (&rep_client),
			    sizeof (rep_client));
		}
	      h_close (clientfd);
	    }
	}
    }

  printf ("Serveur lancé sur le port %s ", prot_params.port);
  if (prot_params.type == sock_tcp)
    {
      printf (" en tcp.\n");
    }
  else
    {
      printf (" en udp.\n");
    }
/* A COMPLETER */

#if 0				/* Code non compilé jusqu'au #endif correspondant */

  /* Vous aurez probablement une partie de votre code
     qui ressemblera au code suivant: */

  requete_t requete;
  /* ... */

  /* Suivant la requête demandée, on prend un verrou
     sur la base de données (sur les fichiers) :
     - en lecture si on fait juste de la consultation
     - en écriture si on fait des modifications
     On charge ensuite la base de donnée
   */
  switch (requete.type)
    {
    case Consulter_Auteur:
    case Consulter_Titre:
    case Consulter_adherent_t:
      /* accès en lecture uniquement */
      bdd_acces_lecture_debut ();
      bdd_load ();
      break;
    case Emprunter:
    case Rendre:
      /* accès en écriture */
      bdd_acces_ecriture_debut ();
      bdd_load ();
      break;
    }
  /* ... traitement de la requète, préparation de la réponse ... */

  /* Suivant l'action demandée, on relâche le verrou
     sur la base de données (sur les fichiers) après
     avoir sauver la base de données si nécessaire
   */
  switch (requete.type)
    {
    case Consulter_Auteur:
    case Consulter_Titre:
    case Consulter_adherent_t:
      /* accès en lecture uniquement */
      bdd_acces_lecture_fin ();
      break;
    case Emprunter:
    case Rendre:
      /* accès en écriture */
      bdd_sauvegarde ();
      bdd_acces_ecriture_fin ();
      break;
    }
  /* ... */
#endif /* fin du code non compilé */

}

/*----------------------------------------------------------*/
/* MAIN : lancement du serveur                               */
/*----------------------------------------------------------*/

int
main (int argc, char **argv)
{

  int c, tflag = 0;
  prot_params.port = PORT_DEFAUT;


  files_conf.fichierAnnuaire=F_ANN_NAME;
  files_conf.fichierCatalogue=F_CAT_NAME;
  while ((c = getopt (argc, argv, "tp:a:d")) != -1)
    {
      switch (c)
	{
	case 't':
	  tflag = 1;
	  break;
	case 'p':
	  prot_params.port = optarg;
	  break;
	 case 'a':
	  files_conf.fichierAnnuaire = optarg;
	  break;
	 case 'd':
	  files_conf.fichierCatalogue= optarg;
	  break;
	case '?':
	  if (optopt == 'p')
	    fprintf (stderr, "Option -%c requiert un argument.\n", optopt);
	  else if (isprint (optopt))
	    fprintf (stderr, "Option '-%c' inconnue.\n", optopt);
	  else
	    fprintf (stderr,
		     "Caractère d'option '\\x%x'.\n inconne.", optopt);
	  return EXIT_FAILURE;
	}
    }
  if (tflag)
    {
      prot_params.type = sock_tcp;
    }
  else
    {
      prot_params.type = sock_udp;
    }
  /* Lancement de l'interface client */
  traitement_serveur ();

  return EXIT_SUCCESS;

}

/*------------------------------------------------------------------*/
