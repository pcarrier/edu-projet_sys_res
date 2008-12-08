#ifndef __TYPES_H__
#define __TYPES_H__
/***********************************************/
/* Définition des constantes de taille maximum */
/***********************************************/

#define LIVRE_LMAX  50
#define ADH_NMAX 50
#define PRETS_NBMAX 5

/****************************************/
/* Définition des structures de données */
/****************************************/

typedef struct
{
  char titre[LIVRE_LMAX + 1];	/* le titre du livre. +1 pour pouvoir gerer le '\0' à la fin des chaines */
  char auteur[ADH_NMAX + 1];	/* L'auteur ou les auteurs du livre, soit son nom et prénom ou son nom d'écrivain */
  unsigned int livre_nbex;	/* le nombre d'exemplaires que possède la bibliothèque */
  unsigned int livre_nbemprunts;	/* Le nombre d'exemplaires empruntés */
  unsigned int livre_dispos;	/* Ceux qui sont disponibles */
} livre_t;

typedef struct
{
  char Nom[ADH_NMAX + 1];	/*nom */
  char Prenom[ADH_NMAX + 1];	/*prenom */
  unsigned int nbPrets;		/* le nombre de prêts */
  char Prets[PRETS_NBMAX][LIVRE_LMAX + 1];	/* la liste des titres empruntés */
} adherent_t;


/****************************************************************
		Code d'erreur renvoyés par les fonctions du module */
typedef enum { ParametresIncorrects = -1, OuvertureFichierImpossible = -2 } ErreurAcces;

#endif
