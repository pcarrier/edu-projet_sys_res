#ifndef __PROTOCOLE_H__
#define __PROTOCOLE_H__

#include <donnees/donnees.h>
#include <common.h>

/*!
 * \brief Opérations disponibles dans le protocole
 *
 * L'opération est le premier élément communiqué au serveur
 * lors d'une requête.
 *
 */
typedef enum
{
  op_consulter_auteur = 0,
  op_consulter_titre = 1,
  op_emprunter = 2,
  op_rendre = 3,
  op_consulter_adherent = 4,
  op_ping = 42
} prot_op_e;

/*!
 * \brief Codes de retour disponibles dans le protocole
 *
 * Le code de retour est le premier élément communiqué au
 * serveur lors d'une requête.
 *
 */
typedef enum
{
  ret_probleme_local = -3,
  ret_operation_impossible = -2,
  ret_inexistant = -1,
  ret_succes = 0,
  ret_pong = 42,
} prot_ret_e;

/*!
 * \brief Type de socket
 *
 * TCP ou UDP
 *
 */
typedef enum
{
  sock_tcp,
  sock_udp
} socktype_e;

/*!
 * \brief Requêtes du client au serveur
 *
 * Les requêtes sont composées d'une opération et d'un paramètre.
 *
 */
typedef struct
{
  prot_op_e operation;		///<  Opération à effectuer
  char param[PARAM_LMAX];	/*!< Paramètre de l'opération, suivant le contexte :
				   - Nom d'auteur
				   - Titre de livre
				   - Nom d'adhérent
				 */
} prot_requete_t;

/*!
 * \brief Réponses du serveur au client
 *
 * Les réponses du serveur sont composées d'un code de retour,
 * de tableaux de livres et adhérents. La fin des résultats est marquée
 * par un nom ou titre vide.
 *
 */
typedef struct
{
  prot_ret_e code;		///< Code de retour
  livre_t livres[RESULT_LMAX];	///< Livres si la requête le requiert
  adherent_t adhs[RESULT_LMAX];	///< Adhérent si la requête le requiert
} prot_reponse_t;

/*!
 * \brief Paramètres du protocole
 *
 * Paramètres réseau utilisés par le client et le serveur, générés au
 * lancement en interprétant les options de la ligne de commande.
 *
 */
typedef struct
{
  char *host;
  socktype_e type;
  char *port;
  int utilisable;
} prot_params_t;

#endif
