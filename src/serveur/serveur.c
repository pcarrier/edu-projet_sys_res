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
#include "reseau_srv.h"
void serveur_appli (char *service, char *protocole);

//Parametres du protocol du serveur (port, type de proto).
prot_params_t prot_params;
//Fichiers de configuration
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
  //struct sockaddr_in sa;
  char hostname[26];
  //On récupère le hostname
  gethostname (hostname, 25);

  //Socket client file descriptor
  int clientfd=0;
  struct sockaddr_in addr_client;

  //Pour récupérer les opérations
  prot_requete_t rqt_client;
  prot_reponse_t rep_client;
  prot_ret_e rqt_status;
  //Pour le fork()
  int pid_fils=getpid();
      //Création de la socket serveur
      sockfd=create_sock(prot_params, hostname);
      //Si tcp, On passe en mode écoute
       serveur_ecoute(prot_params, sockfd, 10);
      while (1)
	{
	  if(prot_params.type==sock_tcp)
	  {
		  clientfd = h_accept (sockfd, &addr_client);

		  pid_fils = fork ();
	  }else{
	  	h_recvfrom(sockfd,(char * ) & rqt_client, sizeof(prot_requete_t), &addr_client);
	  }
	  if (pid_fils == 0)
	    {
	      while((serveur_lire(prot_params, clientfd, &rqt_client)) >0)
		{
		  affiche_requete_informations (rqt_client);
		  rqt_status = traite_requete (rqt_client, &rep_client);
		  affiche_requete_status (rqt_status);
		  serveur_ecrire(prot_params, clientfd, &rep_client);
		}
	       serveur_fermer_client(clientfd);
	      return exit (EXIT_SUCCESS);
	    }else{
		    affiche_requete_informations(rqt_client);
		    rqt_status= traite_requete(rqt_client, &rep_client);
		    affiche_requete_status(rqt_status);
		    serveur_ecrire_udp(prot_params, clientfd, &rep_client, &addr_client);
	    }
    }

}


prot_ret_e
traite_requete (prot_requete_t rqt_client, prot_reponse_t * rep_client)
{
  livre_t livres_results[RESULT_LMAX];
  adherent_t adh_results[RESULT_LMAX];

  switch (rqt_client.operation)
    {
    case (op_consulter_auteur):

      (*rep_client).code =
	trait_consulter_auteur (files_conf.fichier_catalogue,
				rqt_client.param, livres_results);
      memcpy ((*rep_client).livres, livres_results,
	      sizeof (livre_t) * RESULT_LMAX);
      break;
    case (op_consulter_titre):
      (*rep_client).code =
	trait_consulter_titre (files_conf.fichier_catalogue,
			       rqt_client.param, livres_results);
      memcpy ((*rep_client).livres, livres_results,
	      sizeof (livre_t) * RESULT_LMAX);
      break;
    case (op_consulter_adherent):
      (*rep_client).code =
	trait_consulter_adherent (files_conf.fichier_annuaire,
				  rqt_client.param, adh_results);

      memcpy ((*rep_client).adhs, adh_results,
	      sizeof (adherent_t) * RESULT_LMAX);
      break;
    case (op_emprunter):
      (*rep_client).code =
	trait_emprunter (files_conf.fichier_annuaire,
			 files_conf.fichier_catalogue, rqt_client.param);
      break;
    case (op_rendre):
      (*rep_client).code = trait_rendre (files_conf.fichier_annuaire,
					 files_conf.fichier_catalogue,
					 rqt_client.param);
      break;
    case (op_ping):
      (*rep_client).code = ret_pong;
      break;
    default:
      (*rep_client).code = ret_operation_impossible;
      break;
    }
  return (*rep_client).code;
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
  printf ("%s, %s \n", files_conf.fichier_catalogue,
	  files_conf.fichier_annuaire);
  traitement_serveur ();

  return EXIT_SUCCESS;

}

/*------------------------------------------------------------------*/
