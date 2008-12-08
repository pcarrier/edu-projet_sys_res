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

#include<stdio.h>
#include <curses.h>

#include<sys/signal.h>
#include<sys/wait.h>
#include<stdlib.h>

#include "fon.h"     		/* Primitives de la boite a outils */

#define SERVICE_DEFAUT "2000"
#define PROTOCOLE_DEFAUT "udp"

void serveur_appli (char *service, char* protocole);   /* programme serveur */


/******************************************************************************/	
/*---------------- programme serveur ------------------------------*/

int main(int argc,char *argv[])
{

	char *service= SERVICE_DEFAUT; /* numero de service par defaut */
	char *protocole= PROTOCOLE_DEFAUT; /* protocole par defaut */


	/* Permet de passer un nombre de parametre variable a l'executable */
	switch (argc)
 	{
   	case 1:
		  printf("defaut service = %s\n", service);
		  printf("defaut protocole = %s\n", protocole);
		  break;
 	case 2:
		  service=argv[1];
		  printf("defaut protocole = %s\n", protocole);
		  break;
 	case 3 :
		  service=argv[1];
		  protocole=argv[2];
		  break;

   	default :
		  printf("Usage:serveur service (nom ou port) protocole (TCP ou UDP)\n");
		  exit(1);
 	}

	/* service est le service (ou numéro de port) auquel sera affecté
	ce serveur*/
	/* protocole est le protocole qui sera utilisé */
	
	serveur_appli(service, protocole);
	return 0;
}


/******************************************************************************/	
void serveur_appli(char *service, char *protocole)

/* Procedure correspondant au traitemnt du serveur de votre application */

{

/* A completer ... */
struct sockaddr_in adr_interne;
int taille=100, lg_message=100, num_socket;
char *message;
struct sockaddr_in adr_distante;
message=(char*)malloc(taille* sizeof(char));
num_socket=h_socket(AF_INET,SOCK_DGRAM);
adr_socket(service,"localhost","udp",&adr_interne, SERVEUR);
h_bind(num_socket,&adr_interne);
for(;;)
 {
  lg_message=h_recvfrom(num_socket, message, taille, &adr_distante); 
		  printf("%d %s\n",lg_message,message);
  h_sendto(num_socket, message, lg_message, &adr_distante);
 }
h_close(num_socket);
}

/******************************************************************************/	

