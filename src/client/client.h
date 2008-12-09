/**
 * \file client.h
 *
 * \brief Fonctions de communication avec le serveur
 *
 * Chaque fonction renvoie le message à afficher sur le client
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

/**
 * Charge les paramètres
 */
char *client_init (int argc, char **argv);

/**
 * Ouverture de session
 */
char *client_ouvrir_session ();

/**
 * Fermeture d'une session
 */
char *client_fermer_session ();

/**
 * Emprunt d'un livre
 */
char *client_emprunter_livre (char *auteur, char *titre);

/**
 * Consultation d'un livre
 */
char *client_consulter_titre (char *titre);

/**
 * Consultation d'un auteur
 */
char *client_consulter_auteur (char *auteur);

/**
 * Retour d'un livre
 */
char *client_rendre_livre (char *auteur, char *titre);

/**
 * Consultation d'un adhérent
 */
char *client_consulter_adherent (char *nom);

#endif
