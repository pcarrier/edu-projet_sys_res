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
#define PARAM_LMAX 50
#define RESULT_LMAX 10

/*!
 * Opérations disponibles dans le protocole
 */
typedef enum
{
  op_consulter_auteur = 0,
  op_consulter_titre = 1,
  op_emprunter = 2,
  op_rendre = 3,
  op_consulter_adherent = 4
} operation_e;

/*!
 * Erreurs disponibles dans le protocole
 */
typedef enum
{
  ret_operation_impossible = -1,
  ret_inexistant = 0,
  ret_trouve = 1
} retour_e;

/*!
 * Requêtes du client au serveur
 */
typedef struct
{
  operation_e operation;	///<  Opération à effectuer
  char param[PARAM_LMAX];	/*!< Paramètre de l'opération, suivant le contexte :
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
  livre_t livres[RESULT_LMAX];	///< Livres si la requête le requiert
  adherent_t adh;		///< Adhérent si la requête le requiert
} reponse_t;

typedef enum
{
  sock_tcp,
  sock_udp
} socktype_e;

/*!
 * Paramètres de l'application
 *
typedef struct
{
}
*/
