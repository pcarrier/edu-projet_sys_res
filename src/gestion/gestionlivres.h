/********************************************************

	Header du module de Gestion de livres gestionlivres.h
	Auteur: Dominique Vaufreydaz

*********************************************************/

/* Verification de l'inclusion multiple de ce fichier */
#ifndef __GESTIONLIVRES_H__
#define __GESTIONLIVRES_H__
#include <donnees/types.h>
/****************************************************************
 Définition du catalogue et de sa taille maximum en nombre de livres
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
#define LIVRES_NBMAX 1000
extern livre_t Catalogue[LIVRES_NBMAX];

/* Valeur contenant le nombre de livre actuellement dans le catalogue */
extern int cat_nb_livres;

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
