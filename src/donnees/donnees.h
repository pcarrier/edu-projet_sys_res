#ifndef __DONNEES_H__
#define __DONNEES_H__
#include "types.h"

/*
  Ce fichier contient les déclarations publiques nécessaires
  pour manipuler les données renvoyées par le serveur.
 */

/*************************************/
/* Fonctions exportées par le module */
/*************************************/
/**
 * Affiche le titre, l'auteur, le nombre d'exemplaires 
 * acquis paar la bibliothèque, prétés et disponibles.
 */
void afficher_livre (livre_t l);

/**
 * Affiche le nom, le prénom et les prêts montrés sous forme
 * d'une liste de titre de livres.
 */
void afficher_adherent (adherent_t a);

#endif
