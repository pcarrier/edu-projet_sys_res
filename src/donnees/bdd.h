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
/**
 * Tentative de lecture du fichier serveur.lock
 * si fail alors le fichier est en utilisation sinon la méthoode accède
 * et verrouille le fichier
 **/ 
void bdd_acces_lecture_debut ();
/**
 * si l'accès au seveur.lock échoue, alors on quite la méthode
 * sinon la méthode dévérrouille le fichier serveur.lock
 **/
void bdd_acces_lecture_fin ();
/**
 * Tentative d'ouverture du fichier serveur.lock en écriture
 * s'il y a un échec alors le fichier est en utilisation sinon la methode accède
 * et verrouille le fichier
 **/
void bdd_acces_ecriture_debut ();
/**
 * si l'accès au seveur.lock échoue, alors on quite la méthode
 * sinon la méthode dévérrouille le fichier serveur.lock
 **/
void bdd_acces_ecriture_fin ();
/** 
 * Charge le fichier annuaire 
 * Reçoit en paramètre un pointeur vers le nom du fichier,
 * si une erreur est detectée elle sera affichée, et un code d'erreur (-1) sera envoyé
 */
int bdd_load_annuaire (char *a);
/** 
 * Charge le fichier catalogue
 * Reçoit en paramètre un pointeur vers le nom du fichier,
 * si une erreur est detectée elle sera affichée, et un code d'erreur (-1) sera envoyé
 */
int bdd_load_catalogue (char *b);
/** 
 * Enregistre le fichier Annuaire
 *  Reçoit en paramètre un pointeur vers le nom du fichier,
 * si une erreur est detectée elle sera affichée, et un code d'erreur (-1) sera envoyé
 */
int bdd_save_annuaire (char *a);
/** 
 * Enregistre le fichier Catalogue
 *  Reçoit en paramètre un pointeur vers le nom du fichier,
 * si une erreur est detectée elle sera affichée, et un code d'erreur (-1) sera envoyé
*/
int bdd_save_catalogue (char *b);


#endif
