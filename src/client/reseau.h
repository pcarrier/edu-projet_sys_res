#ifndef __CLIENT_RESEAU_H__
#define __CLIENT_RESEAU_H__

#include <reseau/protocole.h>

/**
 * \brief Création du socket client
 */
void client_creer_socket ();

/**
 * \brief Fermeture du socket client
 */
void client_fermer_socket ();

/**
 * \brief Envoi d'une requête déjà formée au serveur
 */
void client_envoyer_requete (prot_requete_t * req);

/**
 * \brief Réception d'une réponse du serveur
 */
prot_reponse_t client_recevoir_reponse ();

/**
 * \brief Traitement d'une requête côté client
 *
 * Envoi d'une requête, réception de la réponse,
 * mesure du temps pris et traitement du code de retour côté client.
 */
prot_reponse_t client_traiter (prot_requete_t * req, double *delai);

/**
 * \brief Gestion des codes de retour du serveur côté client.
 */
int client_gerer_code (prot_ret_e retour, double delai);

#endif
