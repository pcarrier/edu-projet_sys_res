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
#include "reseau.h"

prot_params_t prot_params;
int client_socket = 0;

void
client_ouvrir_session ()
{
  if (prot_params.type == sock_udp)
    {
      fprintf (stderr, "TCP -> pas d'ouverture de session !\n");
    }
  client_creer_socket ();
  printf ("Fini.\n");
}

void
client_fermer_session ()
{
  if (prot_params.type == sock_udp)
    {
      fprintf (stderr, "UDP -> pas de fermeture de session !\n");
    }
  client_fermer_socket ();
  printf ("Fini.\n");
}

int
client_gerer_code (prot_ret_e retour, double delai)
{
  if (retour == ret_trouve)
    {
      printf ("Réponse après %e ms :\n", delai);
      return 1;
    }
  if (retour == ret_pong)
    {
      printf ("Pong (%e ms) !\n", delai);
      return 1;
    }
  if (retour == ret_inexistant)
    {
      fprintf (stderr, "Inexistant (%e ms) !\n", delai);
      return 0;
    }
  fprintf (stderr, "Opération impossible (%e ms) !\n", delai);
  return 0;
}


void
client_ping ()
{
  prot_requete_t req;
  prot_reponse_t rep;
  double delai;
  req.operation = op_ping;
  rep = client_traiter (&req, &delai);
  if (!client_gerer_code (rep.code, delai))
    return;
}

void
client_afficher_livres (livre_t * livres)
{
  livre_t *livre_courant = livres;
  while (livre_courant->titre[0] != '\0')
    {
      afficher_livre (*livre_courant);
      ++livre_courant;
    }
}

void
client_consulter_titre (char *titre)
{
  prot_requete_t req;
  prot_reponse_t rep;
  double delai;
  req.operation = op_consulter_titre;
  strncpy (req.param, titre, PARAM_LMAX);
  rep = client_traiter (&req, &delai);
  if (!client_gerer_code (rep.code, delai))
    return;
  client_afficher_livres (rep.livres);
}

void
client_consulter_auteur (char *auteur)
{
  prot_requete_t req;
  prot_reponse_t rep;
  double delai;
  req.operation = op_consulter_auteur;
  strncpy (req.param, auteur, PARAM_LMAX);
  rep = client_traiter (&req, &delai);
  if (!client_gerer_code (rep.code, delai))
    return;
  client_afficher_livres (rep.livres);
}

void
client_afficher_adherents (adherent_t * adherents)
{
  adherent_t *adherent_courant = adherents;
  while (adherent_courant->nom[0] != '\0')
    {
      afficher_adherent (*adherent_courant);
      ++adherent_courant;
    }
}

void
client_consulter_adherent (char *nom)
{
  prot_requete_t req;
  prot_reponse_t rep;
  double delai;
  req.operation = op_consulter_adherent;
  strncpy (req.param, nom, PARAM_LMAX);
  rep = client_traiter (&req, &delai);
  if (!client_gerer_code (rep.code, delai))
    return;
  client_afficher_adherents (rep.adhs);
}

void
client_emprunter_livre (char *adherent, char *titre)
{
  printf ("OK\n");
}

void
client_rendre_livre (char *adherent, char *titre)
{
  printf ("OK\n");
}

int
client_main_loop ()
{
  int boucler = 1;
  char *commande, *suite;
  while (boucler && (commande = lire_commande ()))
    {
      suite = extraire_parametre (commande);
      if (!strcmp (commande, "quitter"))
	boucler = 0;
      else if (!strcmp (commande, "aide"))
	{
	  extraire_parametre (suite);
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
	client_ouvrir_session ();
      else if (!strcmp (commande, "fermer"))
	client_fermer_session ();
      else if (!strcmp (commande, "titre"))
	client_consulter_titre (suite);
      else if (!strcmp (commande, "auteur"))
	client_consulter_auteur (suite);
      else if (!strcmp (commande, "emprunter"))
	{
	}
      else if (!strcmp (commande, "rendre"))
	{
	}
      else if (!strcmp (commande, "adherent"))
	client_consulter_adherent (suite);
      else if (!strcmp (commande, "ping"))
	client_ping ();
      else
	{
	  fprintf (stderr, "Commande inconnue ! Voir 'aide'.\n");
	}
      free (commande);
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
    {
      prot_params.type = sock_udp;
      client_creer_socket ();
    }
  fancy_prompt();
  client_main_loop ();
  return EXIT_SUCCESS;
}
