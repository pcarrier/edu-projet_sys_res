#ifndef __SRV_RES_H_
#define __SRV_RES_H_
#include <reseau/protocole.h>

int create_sock(prot_params_t param_srv, char * hostname);

int serveur_lire(prot_params_t params,int clientfd, prot_requete_t *rqt_client);

int serveur_ecrire(prot_params_t params, int clientfd, prot_reponse_t * rep_client);

int serveur_ecrire_udp(prot_params_t params, int clientfd, prot_reponse_t * rep_client, struct sockaddr_in *addr_client);

void serveur_fermer_client(int clientfd);

void serveur_ecoute(prot_params_t param, int sockfd, int nbmax);
#endif
