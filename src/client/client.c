/*!
 * \file client.c

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>		/* Primitives de gestion d'écran */
#include <sys/signal.h>
#include <sys/wait.h>
#include <string.h>

#include <reseau/fon.h>		/* primitives de la boite a outils */
#include <reseau/protocole.h>	/* structures de données pour communication client <->serveur */
#include <donnees/donnees.h>
#include "client.h"
#include <common.h>

void client_appli (char *serveur, char *service, char *protocole);
extern void interface_client ();

static char serveur_courant[LongMaxServeur] = SERVEUR_DEFAUT;
static char service_courant[LongMaxService] = PORT_DEFAUT;
static char protocole_courant[LongNomProtocole] = PROTOCOLE_DEFAUT;


/*------------------------------------------------------------------*/
/* CLIENT															*/
/*------------------------------------------------------------------*/

char *
client_init (int *argc, char **argv)
{

  printf
    ("-------------------------------------------------------------------------------------------------\n");
  printf
    ("Usage : client serveur(nom ou @IP) service (nom ou port)  protocole (tcp ou udp)\n");
  printf
    ("Tous les arguments sont optionnels, si omis, des valeurs par défaut sont utilisés.\n");
  printf
    ("-------------------------------------------------------------------------------------------------\n");

  /* Permet de passer un nombre de parametre variable a l'executable */
  switch (*argc)
    {
    case 1:			/* arguments par defaut */
      break;
    case 2:			/* serveur renseigne  */
      strcpy (serveur_courant, argv[1]);
      break;
    case 3:			/* serveur, service renseignes */
      strcpy (serveur_courant, argv[1]);
      strcpy (service_courant, argv[2]);
      break;
    case 4:			/* serveur, service, protocole renseignes */
      strcpy (serveur_courant, argv[1]);
      strcpy (service_courant, argv[2]);
      strcpy (protocole_courant, argv[3]);
      break;
    default:
      printf
	("Usage:client serveur(nom ou @IP)  service (nom ou port)  protocole (tcp ou udp)\n");
      exit (1);
    }
  printf ("Utilisation de serveur : %s\n", serveur_courant);
  printf ("Utilisation de service : %s\n", service_courant);
  printf ("Utilisation de protocole : %s\n\n", protocole_courant);

  return "OK";
}

/*------------------------------------------------------------------*/
/* client_ouvrir_session											*/
/*------------------------------------------------------------------*/

char *
client_ouvrir_session ()
{
  if (!strcmp (protocole_courant, "udp"))
    {
      return "Vous êtes en UDP, pas d'ouverture de session requise\n";
    }
  else if (!strcmp (protocole_courant, "tcp"))
    {
    }
  else
    return "Protocole non connu.\n";

  return "OK";
}

/*****************************************************************************/

char *
client_emprunter_livre (char *auteur, char *titre)
{
  return "OK";
}

/*****************************************************************************/

char *
client_consulter_titre (char *titre)
{
  return "OK";
}

char *
client_consulter_auteur (char *auteur)
{
  return "OK";
}

/*****************************************************************************/

char *
client_rendre_livre (char *auteur, char *titre)
{
  return "OK";
}

/*****************************************************************************/

char *
client_consulter_adherent (char *nom)
{
  return "OK";
}

/*****************************************************************************/

char *
client_fermer_session ()
{
  return "OK";
}
