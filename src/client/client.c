#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>

#include <reseau/fon.h>
#include <reseau/protocole.h>
#include <donnees/donnees.h>
#include <common.h>
#include "client.h"
#include "doc.h"
#include "prompt.h"

prot_params_t prot_params;

/*void client_appli (char *serveur, char *service, char *protocole);*/

char *
client_ouvrir_session ()
{
  if (prot_params.type == sock_udp)
    {
      return "TCP -> pas d'ouverture de session !\n";
    }

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
  if (prot_params.type == sock_udp)
    {
      return "UDP -> pas de fermeture de session !\n";
    }
  return "OK";
}

int
client_creer_socket ()
{
}

int
client_main_loop ()
{
  while (1)
    {
      lire_commande ();
    }
  return EXIT_SUCCESS;
}

int
main (int argc, char **argv)
{
  int c, hflag = 0, tflag = 0, index;
  if (argc == 1)
    client_doc_syntaxe (argv[0]);
  prot_params.host = SERVEUR_DEFAUT;
  prot_params.port = PORT_DEFAUT;
  while ((c = getopt (argc, argv, "hp:t")) != -1)
    {
      switch (c)
	{
	case 't':
	  tflag = 1;
	  break;
	case 'h':
	  hflag = 1;
	  break;
	case 'p':
	  prot_params.port = optarg;
	  break;
	case '?':
	  return EXIT_FAILURE;
	}
    }
  for (index = optind; index < argc; index++)
    prot_params.host = argv[index];
  if (hflag)
    {
      client_doc_syntaxe (argv[0]);
      return EXIT_SUCCESS;
    }
  if (tflag)
    prot_params.type = sock_tcp;
  else
    prot_params.type = sock_udp;

  assert (client_creer_socket ());
  assert (client_main_loop ());
  return EXIT_SUCCESS;
}
