/********************************************************

	Header du module de Gestion de livres GestionLivres.h
	Auteur: Dominique Vaufreydaz

*********************************************************/

/* Verification de l'inclusion multiple de ce fichier */
#ifndef __GESTIONLIVRES_H__
#define __GESTIONLIVRES_H__

/****************************************************************
		Déclaration des types et variables du module */

/* Longueur des champs pour la définition de la structure Livre */
#define LongueurMaxTitre  50
#define LongueurMaxNom 50

typedef struct
{
	char Titre[LongueurMaxTitre + 1];    /* le titre du livre. +1 pour pouvoir gerer le '\0' à la fin des chaines */
	char Auteur[LongueurMaxNom + 1];     /* L'auteur ou les auteurs du livre, soit son nom et prénom ou son nom d'écrivain */
	unsigned int NombreExemplaires;	     /* le nombre d'exemplaires que possède la bibliothèque */
	unsigned int ExemplairesEmpruntes;   /* Le nombre d'exemplaires empruntés */
	unsigned int ExemplairesDisponibles; /* Ceux qui sont disponibles */
} Livre;

/* Définition du catalogue et de sa taille maximum en nombre de livres
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
#define NombreMaximumDeLivres 1000
extern Livre Catalogue[NombreMaximumDeLivres];

/* Valeur contenant le nombre de livre actuellement dans le catalogue */
extern int NombreOuvragesAuCatalogue;

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

void AfficherLivre(Livre l); 

#endif // ifndef __GESTIONLIVRES_H__
