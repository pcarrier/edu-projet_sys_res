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
int client_socket = 0;

char *
client_ouvrir_session ()
{
  if (prot_params.type == sock_udp)
    {
      return "TCP -> pas d'ouverture de session !\n";
    }

  return "OK\n";
}

char *
client_emprunter_livre (char *auteur, char *titre)
{
  return "OK\n";
}

char *
client_consulter_titre (char *titre)
{
  return "OK\n";
}

char *
client_consulter_auteur (char *auteur)
{
  return "OK\n";
}

char *
client_rendre_livre (char *auteur, char *titre)
{
  return "OK\n";
}

char *
client_consulter_adherent (char *nom)
{
  return "OK\n";
}

char *
client_fermer_session ()
{
  if (prot_params.type == sock_udp)
    {
      return "UDP -> pas de fermeture de session !\n";
    }
  return "OK\n";
}

int
client_creer_socket ()
{
  struct sockaddr_in sa;
  client_socket = h_socket (AF_INET, (prot_params.type == sock_tcp) ? SOCK_STREAM : SOCK_DGRAM);
  adr_socket (prot_params.port, prot_params.host, (prot_params.type == sock_tcp) ? "tcp" : "udp", &sa, CLIENT);
  h_bind (client_socket, &sa);
  h_connect (client_socket, &sa);
  h_writes(client_socket,"a",1);
  return 1;
}

int
client_main_loop ()
{
  int boucler = 1;
  char *commande, *suite;
  while (boucler && (commande = lire_commande ()))
    {
      suite = extraire_parametre(commande);
      if (!strcmp (commande, "quitter"))
	boucler = 0;
      else if (!strcmp (commande, "aide"))
	{
	  extraire_parametre(suite);
	  if (!strcmp (suite, "quitter"))
	    client_doc_quitter ();
	  else if (!strcmp (suite, "aide"))
	    client_doc_aide ();
	  else if (!strcmp (suite, "ouvrir"))
	    client_doc_ouvrir ();
	  else if (!strcmp (suite, "fermer"))
	    client_doc_fermer ();
	  else if (!strcmp (suite, "titre"))
	    client_doc_titre ();
	  else if (!strcmp (suite, "auteur"))
	    client_doc_auteur ();
	  else if (!strcmp (suite, "emprunter"))
	    client_doc_emprunter ();
	  else if (!strcmp (suite, "rendre"))
	    client_doc_rendre ();
	  else if (!strcmp (suite, "adherent"))
	    client_doc_adherent ();
	  else
	    client_doc_commandes ();
	}
      else if (!strcmp (commande, "ouvrir"))
	printf ("%s", client_ouvrir_session ());
      else if (!strcmp (commande, "fermer"))
	{
	  printf ("%s", client_fermer_session ());
	}
      else if (!strcmp (commande, "titre"))
	{
	}
      else if (!strcmp (commande, "auteur"))
	{
	}
      else if (!strcmp (commande, "emprunter"))
	{
	}
      else if (!strcmp (commande, "rendre"))
	{
	}
      else if (!strcmp (commande, "adherent"))
	{
	}
      else
	{
	  fprintf (stderr, "Commande inconnue ! Voir 'aide'.\n");
	}
      free(commande);
    }
  return 1;
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
