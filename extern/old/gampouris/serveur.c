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

#include "fon.h"	/* Primitives de la boite a outils */
#include "protocole.h"	/* Types pour la communication client <-> serveur */

#define SERVICE_DEFAUT "1111"
#define PROTOCOLE_DEFAUT "udp"

void serveur_appli (char *service, char *protocole);	/* programme serveur */

#define LongNomProtocole 4
#define LongMaxService   100

static char service_courant[LongMaxService] = SERVICE_DEFAUT;
static char protocole_courant[LongNomProtocole] = PROTOCOLE_DEFAUT;

/*------------------------------------------------------------------*/
/* SERVEUR															*/
/*------------------------------------------------------------------*/

int serveur_init (int *argc, char *argv[])
{
	printf("%d\n", *argc);
	/* Permet de passer un nombre de parametre variable a l'executable */
	switch (*argc)
	{
		case 1:
			break;
		case 2:
			strcpy(service_courant,argv[1]);
			break;
		case 3:
			strcpy(service_courant,argv[1]);
			strcpy(protocole_courant,argv[2]);
			break;
		default:
			printf ("Usage:serveur service (nom ou port) protocole (tcp ou udp)\n");
			exit (1);
	}
	printf ("Utilisation de service : %s\n", service_courant);
	printf ("Utilisation de protocole : %s\n\n", protocole_courant);
	return 0;
}


/*------------------------------------------------------------------*/
void traitement_serveur () {
/* A COMPLETER */

	
}

/*----------------------------------------------------------*/
/* MAIN : lancement du serveur                               */
/*----------------------------------------------------------*/

int main(int argc, char** argv) {
	
	printf ("-------------------------------------------------------------------------------------------------\n");
	printf ("Usage : %s serveur(nom ou @IP) service (nom ou port)  protocole (tcp ou udp)\n", argv[0]);
	printf ("Tous les arguments sont optionnels, si omis, des valeurs par défaut sont utilisés.\n");
	printf ("-------------------------------------------------------------------------------------------------\n");
	
	/* Initialisation de la partie réseau du client */
	serveur_init(&argc, argv);	
	/* Lancement de l'interface client */
	traitement_serveur();
	
	return 0;
	
}


/*------------------------------------------------------------------*/
