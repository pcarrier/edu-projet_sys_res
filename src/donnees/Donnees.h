#ifndef __DONNEES_H__
#define __DONNEES_H__

/*
  Ce fichier contient les déclarations publiques nécessaires
  pour manipuler les données renvoyées par le serveur.
 */

/***********************************************/
/* Définition des constantes de taille maximum */
/***********************************************/

#define LongueurMaxTitre  50
#define LongueurMaxNom 50
#define MaxNbPrets 5

/****************************************/
/* Définition des structures de données */
/****************************************/

typedef struct {
	char Titre[LongueurMaxTitre + 1];	/* le titre du livre. +1 pour pouvoir gerer le '\0' à la fin des chaines */
	char Auteur[LongueurMaxNom + 1];	/* L'auteur ou les auteurs du livre, soit son nom et prénom ou son nom d'écrivain */
	unsigned int NombreExemplaires;	/* le nombre d'exemplaires que possède la bibliothèque */
	unsigned int ExemplairesEmpruntes;	/* Le nombre d'exemplaires empruntés */
	unsigned int ExemplairesDisponibles;	/* Ceux qui sont disponibles */
} Livre;

typedef struct {
	char Nom[LongueurMaxNom + 1];	/*nom */
	char Prenom[LongueurMaxNom + 1];	/*prenom */
	unsigned int nbPrets;	/* le nombre de prêts */
	char Prets[MaxNbPrets][LongueurMaxTitre + 1];	/* la liste des titres empruntés */
} Adherent;

/*************************************/
/* Fonctions exportées par le module */
/*************************************/

void AfficherLivre(Livre l);
void AfficherAdherent(Adherent a);

#endif
