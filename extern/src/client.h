/*
 *  client.h
 *  MIAGE2
 *
 *  Created by Vania Marangozova-Martin on 24/11/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

/* FONCTIONS de communication avec le serveur */
/* Chanque fonction renvoie le message 
qui doit être affiché pour le client */
char *client_init(int *argc, char **argv);
char *client_ouvrir_session();
char *client_emprunter_livre(char *auteur, char *titre);
char *client_consulter_titre(char *titre);
char *client_consulter_auteur(char *auteur);
char *client_rendre_livre(char *auteur, char *titre);
char *client_consulter_adherent(char *nom);
char *client_fermer_session();
/*---------------------------------------------*/
