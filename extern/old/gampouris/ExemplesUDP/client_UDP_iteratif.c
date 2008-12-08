/******************************************************************************/
/*			Application: ...					*/
/******************************************************************************/
/*									      */
/*			 programme  CLIENT				      */
/*									      */
/******************************************************************************/
/*									      */
/*		Auteurs : ... 					*/
/*									      */
/******************************************************************************/	


#include <stdio.h>
#include <curses.h> 		/* Primitives de gestion d'Žcran */
#include <sys/signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "fon.h"   		/* primitives de la boite a outils */

#define SERVICE_DEFAUT "2000"
#define PROTOCOLE_DEFAUT "udp"
#define SERVEUR_DEFAUT "localhost"

void client_appli (char *serveur, char *service, char *protocole);


/*****************************************************************************/
/*--------------- programme client -----------------------*/

int main(int argc, char *argv[])
{

	char *serveur= SERVEUR_DEFAUT; /* serveur par defaut */
	char *service= SERVICE_DEFAUT; /* numero de service par defaut (no de port) */
	char *protocole= PROTOCOLE_DEFAUT; /* protocole par defaut */

	/* Permet de passer un nombre de parametre variable a l'executable */
	switch(argc)
	{
 	case 1 :		/* arguments par defaut */
		  printf("serveur par defaut: %s\n",serveur);
		  printf("service par defaut: %s\n",service);
		  printf("protocole par defaut: %s\n",protocole);
		  break;
  	case 2 :		/* serveur renseigne  */
		  serveur=argv[1];
		  printf("service par defaut: %s\n",service);
		  printf("protocole par defaut: %s\n",protocole);
		  break;
  	case 3 :		/* serveur, service renseignes */
		  serveur=argv[1];
		  service=argv[2];
		  printf("protocole par defaut: %s\n",protocole);
		  break;
  	case 4:			/* serveur, service, protocole renseignes */
		  serveur=argv[1];
		  service=argv[2];
		  protocole=argv[3];
		  break;
	default:
		  printf("Usage:client serveur(nom ou @IP)  service (nom ou port)  protocole (TCP ou UDP)\n");
		  exit(1);
	}

	/* serveur est le nom (ou l'adresse IP) auquel le client va acceder */
	/* service le numero de port sur le serveur correspondant au  */
	/* service desire par le client */
	/* protocole le protocole qui sera utilise pour la communication */
	
	client_appli(serveur,service,protocole);
	return 0;
}

/*****************************************************************************/
void client_appli (char *serveur,char*service,char *protocole)

/* procedure correspondant au traitement du client de votre application */

{

/* a completer .....  */
struct sockaddr_in adr_interne;
struct sockaddr_in adr_distante;
int taille=100, lg_message=100, num_socket;
char *message;
message=(char*)malloc(taille* sizeof(char));
num_socket=h_socket(AF_INET,SOCK_DGRAM);
adr_socket("0","localhost","udp",&adr_interne, CLIENT);
h_bind(num_socket,&adr_interne);
adr_socket(service,"localhost","udp",&adr_distante, CLIENT);
for(;;)
 {
  gets(message);
  h_sendto(num_socket, message, lg_message, &adr_distante);
  lg_message=h_recvfrom(num_socket, message, taille, &adr_distante); 
		  printf("recu : %s\n",message);

 }
h_close(num_socket);

/******************************************************************************/	


 }

/*****************************************************************************/

