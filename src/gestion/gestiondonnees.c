// GestionDonnees.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees/bdd.h"
#include <ctype.h>
#include <unistd.h>
#include <common.h>
void
Usage (const char *NomProgramme)
{
  fprintf (stderr, "Usage : %s [-c|-l] [-a filename] [-d filename]\n", NomProgramme);
  fprintf (stderr, "\t-c: création des fichiers de données.\n");
  fprintf (stderr, "\t-l: lecture des fichiers de données.\n");
  fprintf (stderr, "\t-a: fichier pour ecriture du catalogue.\n");
  fprintf (stderr, "\t-d: fichier pour écriture des adhérents.\n");
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
  int fAnnFlag = 0;
  char *fAnnName = NULL;
  int fCatFlag = 0;
  char *fCatName = NULL;
  int c = 0;
  opterr = 0;

  while ((c = getopt (argc, argv, "cla:d:")) != -1)
    {
      switch (c)
	{
	case 'c':
	  cflag = 1;
	  break;
	case 'l':
	  lflag = 1;
	  break;
	case 'a':
	  fAnnFlag = 1;
	  fAnnName = optarg;
	  break;
	case 'd':
	 fCatFlag=1;
	 fCatName=optarg;
	 break;
	}
    }
   //On attribue les valeur par défaut si les noms n'ont pas été donnés en paramètre.
    if(fCatFlag==0){fCatName=FCATNAME;}
    if(fAnnFlag==0){fAnnName=FANNNAME;}
	

 if(cflag)
    {				/* creation données */
      strcpy (Catalogue[0].Titre, "Da Vinci Code");
      strcpy (Catalogue[0].Auteur, "Dan Brown, Daniel Roche");
      Catalogue[0].livre_nbex = 5;
      Catalogue[0].livre_nbemprunts = 1;
      Catalogue[0].livre_dispos = 4;
      cat_nb_livres++;

      strcpy (Catalogue[1].Titre, "Moi, Bouddha");
      strcpy (Catalogue[1].Auteur, "José Fräches");
      Catalogue[1].livre_nbex = 1;
      Catalogue[1].livre_nbemprunts = 0;
      Catalogue[1].livre_dispos = 1;
      cat_nb_livres++;

      strcpy (Catalogue[2].Titre, "Histoires inédites du Petit Nicolas");
      strcpy (Catalogue[2].Auteur, "René Goscinny, Sempé");
      Catalogue[2].livre_nbex = 2;
      Catalogue[2].livre_nbemprunts = 0;
      Catalogue[2].livre_dispos = 2;
      cat_nb_livres++;

      strcpy (Catalogue[3].Titre, "Le Soleil des Scorta");
      strcpy (Catalogue[3].Auteur, "Laurent Gaudé");
      Catalogue[3].livre_nbex = 2;
      Catalogue[3].livre_nbemprunts = 1;
      Catalogue[3].livre_dispos = 1;
      cat_nb_livres++;

      strcpy (Catalogue[4].Titre, "Un long dimanche de fiançailles");
      strcpy (Catalogue[4].Auteur, "Sébastien Japrisot");
      Catalogue[4].livre_nbex = 3;
      Catalogue[4].livre_nbemprunts = 2;
      Catalogue[4].livre_dispos = 1;
      cat_nb_livres++;

      printf ("Catalogue initialisé avec %i ouvrages\n", cat_nb_livres);

      strcpy (Annuaire[0].Nom, "Martin");
      strcpy (Annuaire[0].Prenom, "Daniel");
      Annuaire[0].nbPrets = 1;
      strcpy (Annuaire[0].Prets[0], "Le Soleil des Scorta");
      ann_nb_adhs++;

      strcpy (Annuaire[1].Nom, "Vinoux");
      strcpy (Annuaire[1].Prenom, "Cyrille");
      Annuaire[1].nbPrets = 0;
      ann_nb_adhs++;

      strcpy (Annuaire[2].Nom, "Guillard");
      strcpy (Annuaire[2].Prenom, "Myriam");
      Annuaire[2].nbPrets = 2;
      strcpy (Annuaire[2].Prets[0], "Un long dimanche de fiançailles");
      strcpy (Annuaire[2].Prets[1], "Da Vinci Code");
      ann_nb_adhs++;

      printf ("Annuaire initialisé avec 3 adhérents\n");

      /* Ecriture des données */
      //Si l'écriture ne se passe pas correctement, affichage erreur puis
      //sortie du programme avec erreur.
      int bdd_save_ret=bdd_save (fAnnName, fCatName);
      switch(bdd_save_ret){
      	case(WErrAnn):
      		fprintf(stderr, "Erreur lors de l'écriture de la base de données %s\n",fAnnName);
		exit(1);
	case(WErrCat):
      		fprintf(stderr, "Erreur lors de l'écriture de la base de données %s\n",fCatName);
		exit(1);	
	case(WErrCat+WErrAnn):
      		fprintf(stderr, "Erreur lors de l'écriture de les bases de données %s et %s\n",fAnnName, fCatName);
		exit(1);
      }

	/*----------------------------------------------------*/
      /* lecture catalogue */
    }
    else if(lflag)
    {

      /* On tente de lire les données */
      int bd_load_ret=bdd_load (fAnnName, fCatName);
      
      switch(bd_load_ret){
      	case(RErrAnn):
      		fprintf(stderr, "Erreur lors de la lecture de la base de données %s\n",fAnnName);
		exit(1);
	case(RErrCat):
      		fprintf(stderr, "Erreur lors de la lecture  de la base de données %s.\n",fCatName);
		exit(1);
	case(RErrCat + RErrAnn):
      		fprintf(stderr, "Erreur lors de la lecture des bases de données %s et %s.\n",fAnnName, fCatName);
		exit(1);

      }
      if (cat_nb_livres == 0)
	{
	  printf ("Aucun livre dans le catalogue\n");
	}
      else
	{
	  printf ("%d livre(s) dans le catalogue\n\n",
		  cat_nb_livres);
	  for (i = 0; i < cat_nb_livres; i++)
	    {
	      afficher_livre (Catalogue[i]);
	    }
	}

      if (ann_nb_adhs == 0)
	{
	  printf ("Aucun adhérent dans l'annuaire\n");
	}
      else
	{
	  printf ("%d adherents(s) dans l'annuaire\n\n",
		  ann_nb_adhs);
	  for (i = 0; i < ann_nb_adhs; i++)
	    {
	      afficher_adherent (Annuaire[i]);
	    }
	}
    }
  else
    Usage (argv[0]);

  return 0;
}
