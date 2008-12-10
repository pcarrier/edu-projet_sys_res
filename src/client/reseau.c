#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <reseau/fon.h>
#include <reseau/protocole.h>

extern int client_socket;
extern prot_params_t prot_params;
struct sockaddr_in sa;

void
client_creer_socket ()
{
  client_socket =
    h_socket (AF_INET,
	      (prot_params.type == sock_tcp) ? SOCK_STREAM : SOCK_DGRAM);
  adr_socket (prot_params.port, prot_params.host,
	      (prot_params.type == sock_tcp) ? "tcp" : "udp", &sa, CLIENT);
  if (prot_params.type == sock_udp)
    h_bind (client_socket, &sa);
  h_connect (client_socket, &sa);
  prot_params.utilisable = 1;
}

void
client_fermer_socket ()
{
  h_close (client_socket);
  prot_params.utilisable = 0;
}

void
client_envoyer_requete (prot_requete_t * req)
{
  if (prot_params.type == sock_udp)
    h_sendto (client_socket, (char *) req, sizeof (prot_requete_t), &sa);
  else
    h_writes (client_socket, (char *) req, sizeof (prot_requete_t));
}

prot_reponse_t
client_recevoir_reponse ()
{
  prot_reponse_t rep;
  if (prot_params.type == sock_udp)
    h_recvfrom (client_socket, (char *) (&rep), sizeof (prot_reponse_t), &sa);
  else
    h_reads (client_socket, (char *) (&rep), sizeof (prot_reponse_t));
  return rep;
}

prot_reponse_t
client_traiter (prot_requete_t * req, double *delai)
{
  struct timespec debut, fin;
  prot_reponse_t rep;
  clock_gettime (CLOCK_MONOTONIC, &debut);
  client_envoyer_requete (req);
  rep = client_recevoir_reponse ();
  clock_gettime (CLOCK_MONOTONIC, &fin);
  *delai =
    1000 * (fin.tv_sec - debut.tv_sec) +
    (fin.tv_nsec - debut.tv_nsec) / 1000000;
  return rep;
}

int
client_gerer_code (prot_ret_e retour, double delai)
{
  if (retour == ret_succes)
    {
      printf ("Réponse après %e ms :\n", delai);
      return 1;
    }
  if (retour == ret_pong)
    {
      printf ("Pong (%e ms) !\n", delai);
      return 1;
    }
  if (retour == ret_inexistant)
    {
      fprintf (stderr, "Inexistant (%e ms) !\n", delai);
      return 0;
    }
  fprintf (stderr, "Opération impossible (%e ms) !\n", delai);
  return 0;
}
