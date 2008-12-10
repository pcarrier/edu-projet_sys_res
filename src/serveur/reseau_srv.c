#include <stdio.h>
#include <stdlib.h>
#include <reseau/fon.h>
#include <reseau/protocole.h>
#include "reseau_srv.h"


int create_sock(prot_params_t param_srv, char * hostname){
	struct sockaddr_in sa;
	int sockfd;
	if(param_srv.type == sock_tcp){
		sockfd=h_socket(AF_INET, SOCK_STREAM);
		adr_socket(param_srv.port, hostname, "tcp", &sa ,SERVEUR);
		h_bind(sockfd, &sa);

	return sockfd;
	}else if(param_srv.type==sock_udp){
		//TODO;
	}
	return -1;
}

int serveur_lire(prot_params_t params,int clientfd, prot_requete_t *rqt_client){
	if(params.type==sock_tcp){
		return h_reads(clientfd, (char *) (rqt_client),sizeof (prot_requete_t));
	}else if(params.type==sock_udp){
		return 0;
	}
	return -1;
}

int serveur_ecrire(prot_params_t params, int clientfd, prot_reponse_t * rep_client){
	if(params.type==sock_tcp){
		return h_writes (clientfd, (char *) (rep_client), sizeof (prot_reponse_t));
	}else if(params.type==sock_udp){
		return 0;
	}
	return -1;

}

void serveur_fermer_client(int clientfd){
	h_close (clientfd);
}
