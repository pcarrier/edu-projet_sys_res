/****************************************************************

	Corps du module de Gestion de livres GestionLivres.c
	Auteur: Dominique Vaufreydaz

*****************************************************************/

#include <stdio.h>
#include "GestionLivres.h"

/****************************************************************
    Déclaration des variables conformément au fichier .h */

/* Déclaration du catalogue contenant au maximum NombreMaximumDeLivres */
Livre Catalogue[NombreMaximumDeLivres];

/* Variable contenant le nombre d'ouvrage courant dans le catalogue
   Cette valeur doit rester cohérente avec la capacité du catalogue */
int NombreOuvragesAuCatalogue = 0;	/* par défault, aucun livre */

/****************************************************************
    Ecriture des fonctions nécessaires au fonctionnement du module */

/*
	Fonction : LireCatalogue

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier à charger.

	Valeur de retour : le nombre de livres lus depuis le fichier,
		0 si aucun n'a pu être lu, un code d'erreur en cas de problème :
		-1 si les paramètres sont incorrects
		-2 si l'on a pas pu ouvrir le fichier

	Remarque : si la fonction ne peut ouvrir le fichier, le catalogue reste
		inchangé.

*/
int
LireCatalogue (const char *NomFichier)
{
  FILE *Fichier;		/* le pointeur sur le descripteur de fichier */
  int NombreLivresLus;		/* Nombres de livres lus dans le fichiers */

  /* Tests des paramètres: pointeur NULL ou chaåne vide */
  if (NomFichier == NULL || NomFichier[0] == '\0')
    return ParametresIncorrects;

  /* Tentative d'ouverture du fichier en lecture binaire et vérification */
  Fichier = fopen (NomFichier, "rb");
  if (Fichier == NULL)
    {
      /* Impossible d'ouvrir le fichier */
      return OuvertureFichierImpossible;
    }

  /* On lit au maximum NombreMaximumDeLivres livres depuis le fichier */
  NombreLivresLus =
    fread (Catalogue, sizeof (Livre), NombreMaximumDeLivres, Fichier);

  /* Fermeture du fichier */
  fclose (Fichier);

  /* Mise a jours des variables du module et retour du résultat */
  NombreOuvragesAuCatalogue = NombreLivresLus;

  return NombreLivresLus;
}

/*
	Fonction : EcrireCatalogue

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier pour la sauvagarde.

	Valeur de retour : le nombre de livres écrits dans le fichier
		ou 0 si l'écriture l'a pu être possible.

	Remarque : le catalogue reste inchangé.

*/
int
EcrireCatalogue (const char *NomFichier)
{
  FILE *Fichier;		/* le pointeur sur le descripteur de fichier */
  int NombreLivresEcrits = 0;	/* Nombres de livres écrits dans le fichiers */

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

  /* Ecriture des livres s'il y en a dans le catalogue */
  if (NombreOuvragesAuCatalogue != 0)
    {
      NombreLivresEcrits =
	fwrite (Catalogue, sizeof (Livre),
		NombreOuvragesAuCatalogue, Fichier);
    }

  /* Fermeture du fichier */
  fclose (Fichier);

  /* On retourne le nombre de livres écrits dans le fichier */
  return NombreLivresEcrits;
}

void
AfficherLivre (Livre l)
{
  fprintf (stderr, "Titre: %s\nAuteur(s): %s\n", l.Titre, l.Auteur);
  fprintf (stderr, "Nombre d'exemplaires : %u\n", l.NombreExemplaires);
  fprintf (stderr, "Exemplaires empruntés : %u\n", l.ExemplairesEmpruntes);
  fprintf (stderr,
	   "Exemplaires disponibles : %u\n\n", l.ExemplairesDisponibles);

}
