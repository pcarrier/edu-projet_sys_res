#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/wait.h>

#include <reseau/fon.h>
#include <reseau/protocole.h>

#include <common.h>
#include <donnees/bdd.h>
#include <donnees/donnees.h>
#include "traitement.h"
#include "affichage.h"
#include <gestion/gestionadherents.h>
#include <gestion/gestionlivres.h>
#include "serveur.h"

void serveur_appli (char *service, char *protocole);

//static char port_courant[PORT_LMAX] = PORT_DEFAUT;
//static char protocole_courant[PROTOCOL_LMAX] = PROTOCOLE_DEFAUT;
prot_params_t prot_params;

db_files_t files_conf;

void
serveur_doc_syntaxe (char *progname)
{
  fprintf (stderr, "Usage : %s [-p port] [-t] [-a filename] [-d filename]\n"
	   "-p port: utiliser le port p plutot que " PORT_DEFAUT "\n"
	   "-t utiliser TPC plutot que UDP\n"
	   "-a utiliser un fichier annuaire différent que celui par défaut\n"
	   "-d utiliser un ficher caatalogue différent que celui par défaut.\n",
	   progname);
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
		      sizeof (prot_requete_t)) > 0)
		{
		  int i;
		  affiche_requete_informations (rqt_client);
		  switch (rqt_client.operation)
		    {
		    case (op_consulter_auteur):

		      rep_client.code =
			trait_consulter_auteur (files_conf.fichier_catalogue,
						rqt_client.param,
						livres_results);
		      // rep_client.livres = (livre_t*) livres_results;

		      for (i = 0; i < LIVRES_NBMAX; i++)
			{
			  afficher_livre (livres_results[i]);
			}
		      break;
		    case (op_consulter_titre):
		      rep_client.code =
			trait_consulter_titre (files_conf.fichier_catalogue,
					       rqt_client.param,
					       livres_results);
		      //rep_client.livres = (livre_t*) livres_results;

		      for (i = 0; i < LIVRES_NBMAX; i++)
			{
			  afficher_livre (livres_results[i]);
			}
		      break;
		    case (op_ping):
		      rep_client.code = ret_pong;
		      break;
		    default:
		      rep_client.code = ret_operation_impossible;
		      break;
		    }
		  h_writes (clientfd, (char *) (&rep_client),
			    sizeof (rep_client));
		}
	      h_close (clientfd);
	      return exit(EXIT_SUCCESS);
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
}

/*----------------------------------------------------------*/
/* MAIN : lancement du serveur                               */
/*----------------------------------------------------------*/

int
main (int argc, char **argv)
{

  int c, tflag = 0;
  prot_params.port = PORT_DEFAUT;


  files_conf.fichier_annuaire = F_ANN_NAME;
  files_conf.fichier_catalogue = F_CAT_NAME;
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
	  files_conf.fichier_annuaire = optarg;
	  break;
	case 'd':
	  files_conf.fichier_catalogue = optarg;
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
