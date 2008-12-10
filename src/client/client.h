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
 * \brief Ouverture de session
 */
void client_ouvrir_session ();

/**
 * \brief Fermeture d'une session
 */
void client_fermer_session ();

/**
 * \brief Envoi d'un ping
 */
void client_ping ();

/**
 * \brief Affichage de livres
 *
 * Affichage d'un tableau de livre dont la
 * fin est indiquée par un marqueur de titre vide
 */
void client_afficher_livres (livre_t * livres);

/**
 * \brief Demande de consultation d'un livre
 */
void client_consulter_titre (char *titre);

/**
 * \brief Demande de consultation d'un auteur
 */
void client_consulter_auteur (char *auteur);

/**
 * \brief Affichage d'adhérents
 *
 * Affichage d'un tableau d'adhérents dont la
 * fin est indiquée par un marqueur de nom vide
 */

void client_afficher_adherents (adherent_t * adherents);

/**
 * \brief Demande d'emprunt d'un livre
 */
void client_emprunter_livre (char *adherent, char *titre);

/**
 * \brief Demande de retour d'un livre
 */
void client_rendre_livre (char *adherent, char *titre);

/**
 * \brief Demande de consultation d'un adhérent
 */
void client_consulter_adherent (char *nom);

/**
 * \brief Boucle principale du client
 *
 * Lit les commandes, en extrait le(s) paramètres
 * et exécute le code correspondant.
 *
 */
int client_main_loop ();

#endif
