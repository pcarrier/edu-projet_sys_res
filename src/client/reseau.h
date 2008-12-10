#ifndef __CLIENT_RESEAU_H__
#define __CLIENT_RESEAU_H__

#include <reseau/protocole.h>

void client_creer_socket ();

void client_fermer_socket ();

void client_envoyer_requete (prot_requete_t * req);

prot_reponse_t client_recevoir_reponse ();

prot_reponse_t client_traiter (prot_requete_t * req, double *delai);

int client_gerer_code (prot_ret_e retour, double delai);

#endif
