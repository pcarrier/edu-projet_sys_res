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
  //sockadr_in *adr = malloc(sizeof(sockadr_in));
  //socket = h_socket(AF_INET, (prot_params.type == sock_tcp) ? SOCK_STREAM : SOCK_DGRAM);
  //h_bind(socket, 
  return 1;
}

int
client_main_loop ()
{
  int boucler = 1;
  char *commande;
  while (boucler && (commande = lire_commande ()))
    {
      if (!strncmp (commande, "quitter", 7))
	boucler = 0;
      else if (!strncmp (commande, "aide", 4))
	{
	  if (strlen (commande) > 5)
	    {
	      commande = commande + 5;
	      if (!strncmp (commande, "quitter", 7))
		client_doc_quitter ();
	      else if (!strncmp (commande, "aide", 4))
		client_doc_aide ();
	      else if (!strncmp (commande, "ouvrir", 6))
		client_doc_ouvrir ();
	      else if (!strncmp (commande, "fermer", 6))
		client_doc_fermer ();
	      else if (!strncmp (commande, "titre", 5))
		client_doc_titre ();
	      else if (!strncmp (commande, "auteur", 6))
		client_doc_auteur ();
	      else if (!strncmp (commande, "emprunter", 9))
		client_doc_emprunter ();
	      else if (!strncmp (commande, "rendre", 6))
		client_doc_rendre ();
	      else if (!strncmp (commande, "adherent", 8))
		client_doc_adherent ();
	      else
		client_doc_commandes ();
	    }
	  else
	    {
	      client_doc_commandes ();
	    }
	}
      else if (!strncmp (commande, "ouvrir", 6))
	{
	  printf ("%s", client_ouvrir_session ());
	}
      else if (!strncmp (commande, "fermer", 6))
	{
	  printf ("%s", client_fermer_session ());
	}
      else if (!strncmp (commande, "titre", 5))
	{
	}
      else if (!strncmp (commande, "auteur", 6))
	{
	}
      else if (!strncmp (commande, "emprunter", 9))
	{
	}
      else if (!strncmp (commande, "rendre", 6))
	{
	}
      else if (!strncmp (commande, "adherent", 8))
	{
	}
      else
	{
	  fprintf (stderr, "Commande inconnue ! Voir 'aide'.\n");
	}
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
