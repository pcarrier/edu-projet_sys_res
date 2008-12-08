#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GestionLivres.h"
#include "GestionAdherents.h"
#include "client.h"

#define SOLUTION
#define TAILLE_LIGNE	256

#define SERVICE_DEFAUT "1111"
#define PROTOCOLE_DEFAUT "udp"
#define SERVEUR_DEFAUT "localhost"

static char ligne[TAILLE_LIGNE];

static void lire_chaine (char *ch, int long_max) {
	if (fgets (ch, long_max, stdin) == NULL)
	{
		fprintf (stderr, "*** erreur: EOF sur stdin\n");
		exit (1);
	}
	ch[strlen (ch) - 1] = '\0';
}

static char lire_caractere () {
	lire_chaine (ligne, TAILLE_LIGNE);
	while (ligne[0] == '\0')
	{
		fprintf (stderr, "*** erreur: caractere attendu\n");
		lire_chaine (ligne, TAILLE_LIGNE);
	}
	return ligne[0];
}

/*----------------------------------------------------------*/
/* interface_client : fonction qui gère les requêtes       */
/*                    client en boucle                      */
/*----------------------------------------------------------*/

void interface_client () {
	int fin = 0;
	
	char auteur[LongueurMaxNom]; /*  nom de l'auteur dont le livre est à consulter/rendre */
	char titre[LongueurMaxTitre];	/*  titre du livre à consulter/rendre */
	
	while (!fin) {
		fprintf (stdout,
				 "===========================\n"
				 "  o - ouvrir une session\n"
				 "  t - consulter des livres (par titre)\n"
				 "  a - consulter des livres (par nom d'auteur)\n"
				 "  e - emprunter un livre\n"
				 "  r - rendre un livre\n"
				 "  f - fermer la session\n"
				 "  q - quitter le client\n" "\nCommande : ");
		switch (lire_caractere ()) {
			
			case 'o':
				 /* A COMPLETER
				 par la lecture des infos au clavier et 
				 par un appel vers une focntion implémentée dans client.c
				 qui traite la requete correspondante 
				*/
			    break;
				
		    case 't':
			    fprintf (stdout, "<-- Consulter les livres par titre -->\n");
				fprintf (stdout, "Entrer un titre :");
				lire_chaine(titre, LongueurMaxTitre);
				/* A COMPLETER
				 par un appel vers une focntion implémentée dans client.c
				 qui traite la requete de consultation de livres par le titre 
				*/
			    break;
			
			case 'a':
			     /* A COMPLETER
				 par la lecture des infos au clavier et 
				 par un appel vers une focntion implémentée dans client.c
				 qui traite la requete correspondante 
				*/
				break;
				
		    case 'e':
				 /* A COMPLETER
				 par la lecture des infos au clavier et 
				 par un appel vers une focntion implémentée dans client.c
				 qui traite la requete correspondante 
				*/
			    break;
				
		    case 'r':
			 /* A COMPLETER
				 par la lecture des infos au clavier et 
				 par un appel vers une focntion implémentée dans client.c
				 qui traite la requete correspondante 
				*/			    break;
		    case 'f':
			    /* A COMPLETER
				 par la lecture des infos au clavier et 
				 par un appel vers une focntion implémentée dans client.c
				 qui traite la requete correspondante 
				*/
			    break;
		    case 'q':
			    fin = !0;
			    break;
		    default:
			    fprintf (stderr,
						 "*** erreur: commande inconnue\n");
		}
	}
}

/*----------------------------------------------------------*/
/* MAIN : lancement du client                               */
/*----------------------------------------------------------*/

int main(int argc, char** argv) {
	 
	printf ("-------------------------------------------------------------------------------------------------\n");
	printf ("Usage : %s serveur(nom ou @IP) service (nom ou port)  protocole (tcp ou udp)\n", argv[0]);
	printf ("Tous les arguments sont optionnels, si omis, des valeurs par défaut sont utilisés.\n");
	printf ("-------------------------------------------------------------------------------------------------\n");

	/* Initialisation de la partie réseau du client */
	client_init(&argc, argv);	
	/* Lancement de l'interface client */
	interface_client();
	
	return 0;

}

