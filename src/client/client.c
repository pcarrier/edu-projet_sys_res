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

char *
client_ouvrir_session ()
{
  if (prot_params.type == sock_udp)
    {
      return "TCP -> pas d'ouverture de session !\n";
    }
  client_creer_socket ();
  return ("Fini.\n");
}

char *
client_emprunter_livre (char *auteur, char *titre)
{
  return "OK\n";
}

char *
client_afficher_livres (livre_t *livres) {
  livre_t *livre_courant;
  while(livre_courant->titre[0] != '\0') {
    afficher_livre(livre_courant);
    ++livre_courant;
  }
}

char *
client_consulter_titre (char *titre)
{
  prot_requete_t req;
  prot_reponse_t rep;
  req.operation = op_consulter_titre;
  strncpy (req.param, titre, PARAM_LMAX);
  client_envoyer_requete (&req);
  rep = client_recevoir_reponse();
  if(rep.code = ret_trouve) {
    client_afficher_livres (rep.livres);
    return "Fin des résultats\n";
  }
  else if(rep.code = ret_inexistant)
    return("Aucun résultat !\n");
  else if(rep.code = ret_operation_impossible)
    return("Opération impossible !\n");
}

char *
client_consulter_auteur (char *auteur)
{
  prot_requete_t req;
  prot_reponse_t rep;
  req.operation = op_consulter_auteur;
  strncpy (req.param, auteur, PARAM_LMAX);
  client_envoyer_requete (&req);
  rep = client_recevoir_reponse();
  if(rep.code = ret_trouve) {
    client_afficher_livres (rep.livres);
    return "Fin des résultats\n";
  }
  else if(rep.code = ret_inexistant)
    return("Aucun résultat !\n");
  else if(rep.code = ret_operation_impossible)
    return("Opération impossible !\n");
}

char *
client_afficher_adherents (adherent_t *adherents) {
  adherent_t *adherent_courant;
  while(adherent_courant->nom[0] != '\0') {
    afficher_adherent(adherent_courant);
    ++adherent_courant;
  }
}

char *
client_consulter_adherent (char *nom)
{
  prot_requete_t req;
  prot_reponse_t rep;
  req.operation = op_consulter_adherent;
  strncpy (req.param, nom, PARAM_LMAX);
  client_envoyer_requete (&req);
  rep = client_recevoir_reponse();
  if(rep.code = ret_trouve) {
    client_afficher_adherents (rep.adherents);
    return "Fin des résultats\n";
  }
  else if(rep.code = ret_inexistant)
    return("Aucun adhérent à ce nom !\n");
  else if(rep.code = ret_operation_impossible)
    return("Opération impossible !\n");
}

char *
client_rendre_livre (char *auteur, char *titre)
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
  client_fermer_socket ();
  return ("Fini.\n");
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
	printf ("%s", client_ouvrir_session ());
      else if (!strcmp (commande, "fermer"))
	{
	  printf ("%s", client_fermer_session ());
	}
      else if (!strcmp (commande, "titre"))
	{
	  printf ("%s", client_consulter_titre (suite));
	}
      else if (!strcmp (commande, "auteur"))
	{
	  printf ("%s", client_consulter_auteur (suite));
	}
      else if (!strcmp (commande, "emprunter"))
	{
	}
      else if (!strcmp (commande, "rendre"))
	{
	}
      else if (!strcmp (commande, "adherent"))
	{
	  printf ("%s", client_consulter_adherent (suite));
	}
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
  client_main_loop ();
  return EXIT_SUCCESS;
}
