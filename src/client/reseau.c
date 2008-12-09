#include <reseau/fon.h>
#include <reseau/protocole.h>

extern int client_socket;
extern prot_params_t prot_params;

void
client_creer_socket ()
{
  struct sockaddr_in sa;
  client_socket = h_socket (AF_INET, (prot_params.type == sock_tcp) ? SOCK_STREAM : SOCK_DGRAM);
  adr_socket (prot_params.port, prot_params.host, (prot_params.type == sock_tcp) ? "tcp" : "udp", &sa, CLIENT);
  if(prot_params.type == sock_udp)
    h_bind (client_socket, &sa);
  h_connect (client_socket, &sa);
}

void
client_fermer_socket ()
{
  h_close(client_socket);
}

void
client_envoyer_requete(prot_requete_t * req)
{
  h_writes(client_socket,(char*)req,sizeof(prot_requete_t));
}

prot_reponse_t
client_recevoir_reponse() {
  prot_reponse_t rep;
  h_reads(client_socket,(char*)(&rep),sizeof(prot_reponse_t));
  return rep;
}
