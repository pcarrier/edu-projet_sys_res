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

/*!
 * Opérations disponibles dans le protocole
 */
typedef enum
{
  consulter_auteur = 0,
  consulter_titre = 1,
  emprunter = 2,
  rendre = 3,
  consulter_adherent = 4
} operation_e;

/*!
 * Erreurs disponibles dans le protocole
 */
typedef enum
{
  operation_impossible = -1,
  inexistant = 0,
  trouve = 1
} retour_e;

/*!
 * Requêtes du client au serveur
 */
typedef struct
{
  operation_e operation;	///<  Opération à effectuer
  char param[MaxLongueurParam];	/*!< Paramètre de l'opération, suivant le contexte :
				  - Nom d'auteur
				  - Titre de livre
				  - Nom d'adhérent
				*/
} requete_t;

/*!
 * Réponses du serveur au client
 */
typedef struct
{
  retour_e code;		///< Code de retour
  livre_t livres[result_lmax];	///< Livres si la requête le requiert
  adherent_t a;			///< Adhérent si la requête le requiert
} reponse_t;

/*!
 * Paramètres de l'application
 *
typedef struct
{
}
*/
