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
#define NombreMaximumDeLivres 1000
#define NombreMaximumDAdherents 50

/**************************************/
/* Déclaration des variables globales */
/**************************************/

/* Déclaration du catalogue et de sa taille maximum en nombre de livres
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
extern Livre Catalogue[NombreMaximumDeLivres];

/* Valeur contenant le nombre de livre actuellement dans le catalogue */
extern int NombreOuvragesAuCatalogue;

/* Déclaration de l'annuaire et de sa taille maximum en nombre d'adhérents
   sous optimum en gestion mémoire mais facilite votre utilisation
   de ce module */
extern Adherent Annuaire[NombreMaximumDAdherents];

/* Valeur contenant le nombre d'adhérents actuellement dans l'annuaire */
extern int NombreAdherentsDansAnnuaire;

/*************************************/
/* Fonctions exportées par le module */
/*************************************/

void BdD_acces_lecture_debut();
void BdD_acces_lecture_fin();
void BdD_acces_ecriture_debut();
void BdD_acces_ecriture_fin();
void BdD_chargement();
int BdD_save();

#endif
