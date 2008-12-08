#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <string.h>

#include <reseau/fon.h>
#include <reseau/protocole.h>
#include <donnees/donnees.h>
#include <common.h>
#include "client.h"

void client_appli (char *serveur, char *service, char *protocole);
extern void interface_client ();

static char serveur_courant[LongMaxServeur] = SERVEUR_DEFAUT;
static char service_courant[LongMaxService] = PORT_DEFAUT;
static char protocole_courant[LongNomProtocole] = PROTOCOLE_DEFAUT;

char *
client_init (int argc, char **argv)
{
  /*  while ((c = get ()))
    switch (*argc)
      {
	break;
	strcpy (serveur_courant, argv[1]);
	break;
	strcpy (serveur_courant, argv[1]);
	strcpy (service_courant, argv[2]);
	break;
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
  */
}

char *
client_ouvrir_session ()
{
  if (!strcmp (protocole_courant, "udp"))
    {
      return "Vous êtes en UDP, pas d'ouverture de session requise\n";
    }
  else if (!strcmp (protocole_courant, "tcp"))
    {
      printf ("???");
    }
  else
    return "Protocole non connu.\n";
  return "OK";
}

char *
client_emprunter_livre (char *auteur, char *titre)
{
  return "OK";
}

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

char *
client_rendre_livre (char *auteur, char *titre)
{
  return "OK";
}

char *
client_consulter_adherent (char *nom)
{
  return "OK";
}

char *
client_fermer_session ()
{
  return "OK";
}

int
main (int argc, char **argv)
{
  int c, tflag = 0, index;
  char *port, *serveur, *protocole;
  while ((c = getopt (argc, argv, "p:t")) != -1) {
    switch (c) {
    case 't':
      tflag = 1;
      break;
    case 'p':
      port = optarg;
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
  for (index = optind; index < argc; index++)
    serveur = argv[index];
  if(tflag)
    protocole = "tcp";
  else
    protocole = "udp";
  return EXIT_SUCCESS;
}
