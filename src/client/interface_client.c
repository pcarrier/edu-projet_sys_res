#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gestion/gestionlivres.h>
#include <gestion/gestionadherents.h>
#include "client.h"
#include <common.h>

void
interface_client ()
{
  int fin = 0;
  char *infos = NULL;

  char auteur[ADH_NMAX];	/*  nom de l'auteur dont le livre est à consulter/rendre */
  char titre[LIVRE_LMAX];	/*  titre du livre à consulter/rendre */

  while (!fin)
    {
      fprintf (stdout,
	       "===========================\n"
	       "  o - ouvrir une session\n"
	       "  t - consulter des livres (par titre)\n"
	       "  a - consulter des livres (par nom d'auteur)\n"
	       "  e - emprunter un livre\n"
	       "  r - rendre un livre\n"
	       "  f - fermer la session\n"
	       "  q - quitter le client\n" "\nCommande : ");

      /* Suivant l'action demandée, on demande les informations
         supplémentaires nécessaires et on appelle une fonction
         correspondante dans client.c pour faire le travail
       */
      switch (1)
	{
	case 'o':
	  /* A COMPLETER
	     par un appel vers une fonction implémentée dans client.c
	     qui traite la requete correspondante 
	   */
	  break;

	case 't':
	  fprintf (stdout, "<-- Consulter les livres par titre -->\n");
	  fprintf (stdout, "Entrer un titre :");
	  lire_chaine (titre, LIVRE_LMAX);
	  infos = client_consulter_titre (titre);
	  break;

	case 'a':
	  /* A COMPLETER
	     par la lecture des infos au clavier et
	     par un appel vers une fonction implémentée dans client.c
	     qui traite la requete correspondante 
	   */
	  break;

	case 'e':
	  /* A COMPLETER
	     par la lecture des infos au clavier et
	     par un appel vers une fonction implémentée dans client.c
	     qui traite la requete correspondante
	   */
	  break;

	case 'r':
	  /* A COMPLETER
	     par la lecture des infos au clavier et
	     par un appel vers une fonction implémentée dans client.c
	     qui traite la requete correspondante
	   */ break;
	case 'q':
	  fin = !0;
	  break;
	default:
	  fprintf (stderr, "*** erreur: commande inconnue\n");
	}

      printf ("%s", infos);
    }
}
