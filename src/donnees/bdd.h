#ifndef __BDD_H__
#define __BDD_H__

/*
  Ce fichier contient les déclarations publiques nécessaires
  pour que le serveur puisse charger, manipuler et sauver les
  données de la bibliothèque.
 */

/**
 * Inclusion du header donnees.h
 */
#include "donnees.h"
#include <common.h>
/***********************************************/
/* Définition des constantes de taille maximum */
/***********************************************/

/**************************************/
/* Déclaration des variables globales */
/**************************************/

/**
 * Déclaration du catalogue et de sa taille maximum en nombre de livres
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module
  */
extern livre_t Catalogue[LIVRES_NBMAX];

/**
 *   Valeur contenant le nombre de livre actuellement dans le catalogue
 */
extern int cat_nb_livres;

/**
 * Déclaration de l'annuaire et de sa taille maximum en nombre d'adhérents
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module
 */
extern adherent_t Annuaire[ADHS_NBMAX];

/**
 * Valeur contenant le nombre d'adhérents actuellement dans l'annuaire 
*/
extern int ann_nb_adhs;

/*************************************/
/* Fonctions exportées par le module */
/*************************************/

void bdd_acces_lecture_debut ();
void bdd_acces_lecture_fin ();
void bdd_acces_ecriture_debut ();
void bdd_acces_ecriture_fin ();
int bdd_load (char *a, char *b);
int bdd_load_annuaire (char *a);
int bdd_load_catalogue (char *b);
int bdd_save (char *a, char *b);
int bdd_save_annuaire (char *a);
int bdd_save_catalogue (char *b);


#endif
