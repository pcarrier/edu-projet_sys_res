// GestionDonnees.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees/bdd.h"

/*Censé etre utile à Getopt*/
#include <ctype.h>
#include <unistd.h>
void
Usage (const char *NomProgramme)
{
  fprintf (stderr, "Usage : %s [-c|-l]\n", NomProgramme);
  fprintf (stderr, "\t-c: création des fichiers de données\n");
  fprintf (stderr, "\t-l: lecture des fichiers de données\n");
}

int
main (int argc, char *argv[])
{
  int i;

  /* Vérification des paramètres :
     - nombre de paramètres ok
     - le second est le debut d'une option
     - le dernier n'est pas le début d'une option et n'est pas vide */

//      if (argc != 2 || argv[1][0] != '-') {
  /* Usage affiche l'aide sur le programme */
//              Usage(argv[0]);
//              return 1;
//      }
  int cflag = 0;
  int lflag = 0;
  int fflag = 0;
  char *fvalue = NULL;
  int c = 0;
  opterror = 0;

  while ((c = getopt (argc, argv, "clf:")) != -1)
    {
      switch (c)
	{
	case 'c':
	  cflag = 1;
	case 'l':
	  lflag = 1;
	case 'f':
	  fflag = 1;
	  fvalue = optarg;
	  printf ("%s", fvalue);
	}
    }

  if (!strcmp (argv[1], "-c"))
    {				/* creation données */
      strcpy (Catalogue[0].Titre, "Da Vinci Code");
      strcpy (Catalogue[0].Auteur, "Dan Brown, Daniel Roche");
      Catalogue[0].NombreExemplaires = 5;
      Catalogue[0].ExemplairesEmpruntes = 1;
      Catalogue[0].ExemplairesDisponibles = 4;
      NombreOuvragesAuCatalogue++;

      strcpy (Catalogue[1].Titre, "Moi, Bouddha");
      strcpy (Catalogue[1].Auteur, "José Fräches");
      Catalogue[1].NombreExemplaires = 1;
      Catalogue[1].ExemplairesEmpruntes = 0;
      Catalogue[1].ExemplairesDisponibles = 1;
      NombreOuvragesAuCatalogue++;

      strcpy (Catalogue[2].Titre, "Histoires inédites du Petit Nicolas");
      strcpy (Catalogue[2].Auteur, "René Goscinny, Sempé");
      Catalogue[2].NombreExemplaires = 2;
      Catalogue[2].ExemplairesEmpruntes = 0;
      Catalogue[2].ExemplairesDisponibles = 2;
      NombreOuvragesAuCatalogue++;

      strcpy (Catalogue[3].Titre, "Le Soleil des Scorta");
      strcpy (Catalogue[3].Auteur, "Laurent Gaudé");
      Catalogue[3].NombreExemplaires = 2;
      Catalogue[3].ExemplairesEmpruntes = 1;
      Catalogue[3].ExemplairesDisponibles = 1;
      NombreOuvragesAuCatalogue++;

      strcpy (Catalogue[4].Titre, "Un long dimanche de fiançailles");
      strcpy (Catalogue[4].Auteur, "Sébastien Japrisot");
      Catalogue[4].NombreExemplaires = 3;
      Catalogue[4].ExemplairesEmpruntes = 2;
      Catalogue[4].ExemplairesDisponibles = 1;
      NombreOuvragesAuCatalogue++;

      printf ("Catalogue initialisé avec 5 ouvrages\n");

      strcpy (Annuaire[0].Nom, "Martin");
      strcpy (Annuaire[0].Prenom, "Daniel");
      Annuaire[0].nbPrets = 1;
      strcpy (Annuaire[0].Prets[0], "Le Soleil des Scorta");
      NombreAdherentsDansAnnuaire++;

      strcpy (Annuaire[1].Nom, "Vinoux");
      strcpy (Annuaire[1].Prenom, "Cyrille");
      Annuaire[1].nbPrets = 0;
      NombreAdherentsDansAnnuaire++;

      strcpy (Annuaire[2].Nom, "Guillard");
      strcpy (Annuaire[2].Prenom, "Myriam");
      Annuaire[2].nbPrets = 2;
      strcpy (Annuaire[2].Prets[0], "Un long dimanche de fiançailles");
      strcpy (Annuaire[2].Prets[1], "Da Vinci Code");
      NombreAdherentsDansAnnuaire++;

      printf ("Annuaire initialisé avec 3 adhérents\n");

      /* Ecriture des données */
      BdD_sauvegarde ();

	/*----------------------------------------------------*/
      /* lecture catalogue */
    }
  else if (!strcmp (argv[1], "-l"))
    {

      /* On tente de lire les données */
      BdD_chargement ();
      if (NombreOuvragesAuCatalogue == 0)
	{
	  printf ("Aucun livre dans le catalogue\n");
	}
      else
	{
	  printf ("%d livre(s) dans le catalogue\n\n",
		  NombreOuvragesAuCatalogue);
	  for (i = 0; i < NombreOuvragesAuCatalogue; i++)
	    {
	      AfficherLivre (Catalogue[i]);
	    }
	}

      if (NombreAdherentsDansAnnuaire == 0)
	{
	  printf ("Aucun adhérent dans l'annuaire\n");
	}
      else
	{
	  printf ("%d adherents(s) dans l'annuaire\n\n",
		  NombreAdherentsDansAnnuaire);
	  for (i = 0; i < NombreAdherentsDansAnnuaire; i++)
	    {
	      AfficherAdherent (Annuaire[i]);
	    }
	}
    }
  else
    Usage (argv[0]);

  return 0;
}
