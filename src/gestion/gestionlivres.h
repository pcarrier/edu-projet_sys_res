/********************************************************

	Header du module de Gestion de livres gestionlivres.h
	Auteur: Dominique Vaufreydaz

*********************************************************/

/* Verification de l'inclusion multiple de ce fichier */
#ifndef __GESTIONLIVRES_H__
#define __GESTIONLIVRES_H__

/****************************************************************
		Déclaration des types et variables du module */

/* Longueur des champs pour la définition de la structure livre_t */
#define livre_lmax  50
#define adh_nmax 50

typedef struct
{
  char Titre[livre_lmax + 1];	/* le titre du livre. +1 pour pouvoir gerer le '\0' à la fin des chaines */
  char Auteur[adh_nmax + 1];	/* L'auteur ou les auteurs du livre, soit son nom et prénom ou son nom d'écrivain */
  unsigned int livre_nbex;	/* le nombre d'exemplaires que possède la bibliothèque */
  unsigned int livre_nbemprunts;	/* Le nombre d'exemplaires empruntés */
  unsigned int livre_dispos;	/* Ceux qui sont disponibles */
} livre_t;

/* Définition du catalogue et de sa taille maximum en nombre de livres
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
#define nb_max_livres 1000
extern livre_t Catalogue[nb_max_livres];

/* Valeur contenant le nombre de livre actuellement dans le catalogue */
extern int cat_nb_livres;

/****************************************************************
		Code d'erreur renvoyés par les fonctions du module */
enum
{ ParametresIncorrects = -1, OuvertureFichierImpossible = -2 };

/****************************************************************
		Fonctions exportées par le module */

/*
	Fonction : LireCatalogue

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier à charger.

	Valeur de retour : le nombre de livres lus depuis le fichier
		ou 0 si aucun n'a pu àtre lu.

	Remarque : si la fonction ne peut ouvrir le fichier, le catalogue reste
		inchangé.

*/
int LireCatalogue (const char *NomFichier);

/*
	Fonction : EcrireCatalogue

	Paramètre : un pointeur sur une chaine terminée par
		le caractère '\0' contenant le nom du fichier pour la sauvegarde.

	Valeur de retour : le nombre de livres écrits dans le fichier
		ou 0 si l'écriture l'a pu être possible.

	Remarque : le catalogue reste inchangé.

*/
int EcrireCatalogue (const char *NomFichier);

void afficher_livre (livre_t l);

#endif // ifndef __GESTIONLIVRES_H__
