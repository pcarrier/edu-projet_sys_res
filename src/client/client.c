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
#include "doc.h"

prot_params_t prot_params;

/*void client_appli (char *serveur, char *service, char *protocole);*/

char *
client_ouvrir_session ()
{
  if (prot_params.type == sock_udp)
    {
      return "Vous êtes en UDP, pas d'ouverture de session requise !\n";
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
      return "Vous êtes en UDP, pas de fermeture de session requise !\n";
    }
  return "OK";
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
  printf("%s,%i,%s\n",prot_params.host,prot_params.type,prot_params.port);
  return EXIT_SUCCESS;
}
