/*
 *  types_communication.h
 *  MIAGE2
 *
 *  Created by Vania Marangozova-Martin on 23/11/06.
 *  Modified by Vincent Danjean 4/12/06.
 *  Copyright 2006-2007 UJF
 *
 */
#include "donnees/donnees.h"

//types des operations sur la bibliotheque
#define MaxLongueurParam 50
#define result_lmax 10

/* Liste des différents types de requêtes possibles */
#define consulter_auteur   0
#define consulter_titre    1
#define Emprunter          2
#define Rendre             3
#define consulter_adherent 4

//type du message de requête, communication client -> serveur
typedef struct {
	/* une des constante définie ci-dessus */
	int type;
	/* Une chaîne qui sera (suivant le type de requête) :
	   -    un auteur
	   - ou un titre
	   - ou un nom d'adhérent
	 */
	char param[MaxLongueurParam];
} requete_t;

//type du message de réponse, communication serveur -> client
typedef struct {
	/* Un code de retour pour indiquer si l'opération c'est bien passée
	   si la requete concerne les livres
	   -1 : operation impossible, 
	   0 : le livre n'existe pas
	   >=1 : nombre de livres trouvés
	   si la requête concerne les adhérents
	   -1 : operation impossible, 
	   0 : l'adhérent n'existe pas
	   1 : adhérent trouvé
	 */
	int code;

	/* Partie remplie uniquement si la requête demande des livres */
	livre_t livres[result_lmax];
	/* Partie remplie uniquement si la requête conserne un adhérent */
	adherent_t a;
} reponse_t;

