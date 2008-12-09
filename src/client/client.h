/**
 * \file client.h
 *
 * \brief Fonctions de communication avec le serveur
 *
 * Chaque fonction renvoie le message à afficher sur le client
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <reseau/protocole.h>

/**
 * Ouverture de session
 */
void client_ouvrir_session ();

/**
 * Fermeture d'une session
 */
void client_fermer_session ();

int client_gerer_code (prot_ret_e retour, double delai);

/**
 * Envoi d'un ping
 */
void client_ping ();

/**
 * Affichage d'un tableau de livre dont la
 * fin est indiquée par un marqueur de titre vide
 */
void client_afficher_livres (livre_t * livres);

/**
 * Consultation d'un livre
 */
void client_consulter_titre (char *titre);

/**
 * Consultation d'un auteur
 */
void client_consulter_auteur (char *auteur);

/**
 * Affichage d'un tableau d'adhérents dont la
 * fin est indiquée par un marqueur de nom vide
 */

void client_afficher_adherents (adherent_t * adherents);

/**
 * Emprunt d'un livre
 */
void client_emprunter_livre (char *adherent, char *titre);

/**
 * Retour d'un livre
 */
void client_rendre_livre (char *adherent, char *titre);

/**
 * Consultation d'un adhérent
 */
void client_consulter_adherent (char *nom);

/**
 * \brief Boucle principale du client
 *
 * Lit les commandes et les exécute
 *
 */
int client_main_loop ();

#endif
