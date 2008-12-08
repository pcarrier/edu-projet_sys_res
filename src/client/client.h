/*!
 * \file client.h
 * \brief Fonctions de communication avec le serveur
 *
 * Chaque fonction renvoie le message affiché sur le client
 */

char *client_init(int *argc, char **argv);
char *client_ouvrir_session();
char *client_emprunter_livre(char *auteur, char *titre);
char *client_consulter_titre(char *titre);
char *client_consulter_auteur(char *auteur);
char *client_rendre_livre(char *auteur, char *titre);
char *client_consulter_adherent(char *nom);
char *client_fermer_session();
