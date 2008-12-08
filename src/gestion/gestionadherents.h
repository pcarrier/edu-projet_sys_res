#ifndef __GESTIONADHERENTS_H__
#define __GESTIONADHERENTS_H__

#include "gestion/gestionlivres.h"

//LonguerMaxNom défini dans gestionlivres
#define MaxNbPrets 5

typedef struct
{
  char Nom[adh_nmax + 1];	/*nom */
  char Prenom[adh_nmax + 1];	/*prenom */
  unsigned int nbPrets;		/* le nombre de prêts */
  char Prets[MaxNbPrets][livre_lmax + 1];	/* la liste des titres empruntés */
} adherent_t;

/* Définition de l'annuaire et de sa taille maximum en nombre d'adhérents
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
#define nb_max_adhs 50
extern adherent_t Annuaire[nb_max_adhs];

/* Valeur contenant le nombre d'adhérents actuellement dans l'annuaire */
extern int ann_nb_adhs;

/****************************************************************
		Fonctions exportées par le module */

/*
	Fonction : LireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
             le caractère '\0' contenant le nom du fichier à charger.

	Valeur de retour : le nombre d'adhérents lus depuis le fichier
	     ou 0 si aucun n'a pu être lu.

	Remarque : si la fonction ne peut ouvrir le fichier, l'annuaire reste
	     inchangé.

*/
int LireAnnuaire (const char *NomFichier);

/*
	Fonction : EcrireAnnuaire

	Paramètre : un pointeur sur une chaine terminée par
	    le caractère '\0' contenant le nom du fichier pour la sauvegarde.

	Valeur de retour : le nombre d'adhérents écrits dans le fichier
	    ou 0 si l'écriture l'a pu être possible.

	Remarque : l'annuaire reste inchangé.

*/
int EcrireAnnuaire (const char *NomFichier);

#endif // ifndef __GESTIONADHERENTS_H__
