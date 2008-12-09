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

#include <ctype.h>
#include <unistd.h>

void serveur_appli (char *service, char *protocole);	/* programme serveur */

static char service_courant[PORT_LMAX] = PORT_DEFAUT;
static char protocole_courant[PROTOCOL_LMAX] = PROTOCOLE_DEFAUT;

/*------------------------------------------------------------------*/
/* SERVEUR															*/
/*------------------------------------------------------------------*/

void serveur_doc_syntaxe(char *progname){
	fprintf(stderr, "Usage : %s [-p port] [-t]\n"
			"-p port: utiliser le port p plutot que " PORT_DEFAUT "\n"
			"-t utiliser TPC plutot que UDP\n", progname);
}
/*
void
Usage ()
{
  printf
    ("-------------------------------------------------------------------------------------------------\n");
  printf
    ("Usage : %s serveur(nom ou @IP) service (nom ou port)  protocole (tcp ou udp)\n",
     argv[0]);
  printf
    ("Tous les arguments sont optionnels, si omis, des valeurs par défaut sont utilisés.\n");
  printf
    ("-------------------------------------------------------------------------------------------------\n");

}
*/

/*
int
serveur_init (int *argc, char *argv[])
{
  // printf ("%d\n", *argc);
  // Permet de passer un nombre de parametre variable a l'executable /
  switch (*argc)
    {
    case 1:
      break;
    case 2:
      strcpy (service_courant, argv[1]);
      break;
    case 3:
      strcpy (service_courant, argv[1]);
      strcpy (protocole_courant, argv[2]);
      break;
    default:
      printf ("Usage:serveur service (nom ou port) protocole (tcp ou udp)\n");
      exit (1);
    }
  printf ("Utilisation de service : %s\n", service_courant);
  printf ("Utilisation de protocole : %s\n\n", protocole_courant);
  return 0;
}
*/
/*------------------------------------------------------------------*/
void
traitement_serveur ()
{
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
  int c;
  char * portValue=NULL;

  while((c=getopt(argc, argv, "t:p:"))!=1)
  {
      	 strcpy(protocole_courant,"udp");

	  switch(c){
		  case('t'):
      			strcpy(protocole_courant,"tcp");
			break;
		  case('p'):
      			strcpy(service_courant ,optarg);
			break;
	  }
  }
  printf("Port %s , Protocole : %s \n", service_courant, protocole_courant); 
  /* Initialisation de la partie réseau du client */
  //serveur_init (&argc, argv);
  /* Lancement de l'interface client */
  traitement_serveur ();

  return 0;

}

/*------------------------------------------------------------------*/
