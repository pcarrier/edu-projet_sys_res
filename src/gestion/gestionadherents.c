/*
 *  Gestionadherent_ts.c
 *  MIAGE2
 *
 *  Created by Vania Marangozova-Martin on 23/11/06.
 *  Copyright 2006 UJF
 *
 */

#include <stdio.h>
#include "gestionadherents.h"

/****************************************************************
    Déclaration des variables conformément au fichier .h */

/* Déclaration de l'annuaire contenant au maximum nb_max_adherents */
adherent_t Annuaire[ADHS_NBMAX];

/* Variable contenant le nombre d'adhérents courant dans l'annuaire
   Cette valeur doit rester cohérente avec la capacité de l'annuaire */
int ann_nb_adhs = 0;		/* par défault, aucun adherent */

/****************************************************************
    Ecriture des fonctions nécessaires au fonctionnement du module */

/*
	Fonction : LireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier à charger.

	Valeur de retour : le nombre d'adhérents lus depuis le fichier,
		0 si aucun n'a pu être lu, un code d'erreur en cas de problème :
		-1 si les paramètres sont incorrects
		-2 si l'on a pas pu ouvrir le fichier

	Remarque : si la fonction ne peut ouvrir le fichier, l'annaire reste
		inchangé.

*/
int
LireAnnuaire (const char *NomFichier)
{
  FILE *Fichier;		/* le pointeur sur le descripteur de fichier */
  int nb_adherents_lus;		/* Nombres d'adhérents lus dans le fichiers */

  /* Tests des paramètres: pointeur NULL ou chaîne vide */
  if (NomFichier == NULL || NomFichier[0] == '\0')
    return ParametresIncorrects;

  /* Tentative d'ouverture du fichier en lecture binaire et vérification */
  Fichier = fopen (NomFichier, "rb");
  if (Fichier == NULL)
    {
      /* Impossible d'ouvrir le fichier */
      return OuvertureFichierImpossible;
    }

  /* On lit au maximum nb_max_adherents adhérents depuis le fichier */
  nb_adherents_lus =
    fread (Annuaire, sizeof (adherent_t), ADHS_NBMAX, Fichier);

  /* Fermeture du fichier */
  fclose (Fichier);

  /* Mise a jours des variables du module et retour du résultat */
  ann_nb_adhs = nb_adherents_lus;

  return nb_adherents_lus;
}

/*
	Fonction : EcrireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier pour la sauvagarde.

	Valeur de retour : le nombre d'adhérents écrits dans le fichier
		ou 0 si l'écriture l'a pu être possible.

	Remarque : le repertoire reste inchangé.

*/
int
EcrireAnnuaire (const char *NomFichier)
{
  FILE *Fichier;		/* le pointeur sur le descripteur de fichier */
  int nb_adherents_ecrits = 0;	/* Nombres d'adhérents écrits dans le fichiers */

  /* Tests des paramètres: pointeur NULL ou chaîne vide */
  if (NomFichier == NULL || NomFichier[0] == '\0')
    return ParametresIncorrects;

  /* Tentative d'ouverture du fichier en écriture binaire et vérification */
  Fichier = fopen (NomFichier, "wb");
  if (Fichier == NULL)
    {
      /* Impossible d'ouvrir le fichier */
      return OuvertureFichierImpossible;
    }

  /* Ecriture des adhérents s'il y en a dans le repertoire */
  if (ann_nb_adhs != 0)
    {
      nb_adherents_ecrits =
	fwrite (Annuaire, sizeof (adherent_t), ann_nb_adhs, Fichier);
    }

  /* Fermeture du fichier */
  fclose (Fichier);

  /* On retourne le nombre de livres écrits dans le fichier */
  return nb_adherents_ecrits;
}
