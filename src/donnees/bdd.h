#ifndef __BDD_H__
#define __BDD_H__

/*
  Ce fichier contient les déclarations publiques nécessaires
  pour que le serveur puisse charger, manipuler et sauver les
  données de la bibliothèque.
 */

#include "donnees.h"

/***********************************************/
/* Définition des constantes de taille maximum */
/***********************************************/
#define nb_max_livres 1000
#define nb_max_adhs 50

/**************************************/
/* Déclaration des variables globales */
/**************************************/

/* Déclaration du catalogue et de sa taille maximum en nombre de livres
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
extern Livre Catalogue[nb_max_livres];

/* Valeur contenant le nombre de livre actuellement dans le catalogue */
extern int cat_nb_livres;

/* Déclaration de l'annuaire et de sa taille maximum en nombre d'adhérents
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
extern Adherent Annuaire[nb_max_adhs];

/* Valeur contenant le nombre d'adhérents actuellement dans l'annuaire */
extern int ann_nb_adhs;

/*************************************/
/* Fonctions exportées par le module */
/*************************************/

void bdd_acces_lecture_debut();
void bdd_acces_lecture_fin();
void bdd_acces_ecriture_debut();
void bdd_acces_ecriture_fin();
void bdd_load();
int bdd_save(char * a, char * b);
int bdd_save_annuaire(char * a);
int bdd_save_catalogue(char * b);


#endif
