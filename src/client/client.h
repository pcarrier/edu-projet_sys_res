/*!
 * \file client.h
 * \brief Fonctions de communication avec le serveur
 *
 * Chaque fonction renvoie le message à afficher sur le client
 */

/*!
 * \brief Initialisation du client
 *
 * Charge les paramètres
 */
char *client_init (int *argc, char **argv);

/*!
 * \brief Ouverture de session
 */
char *client_ouvrir_session ();

/*!
 * \brief Emprunt d'un livre
 */
char *client_emprunter_livre (char *auteur, char *titre);

/*!
 * \brief Consultation d'un livre
 */
char *client_consulter_titre (char *titre);

/*!
 * \brief Consultation d'un auteur
 */
char *client_consulter_auteur (char *auteur);

/*!
 * \brief Retour d'un livre
 */
char *client_rendre_livre (char *auteur, char *titre);

/*!
 * \brief Consultation d'un adhérent
 */
char *client_consulter_adherent (char *nom);

/*!
 * Fermeture d'une session
 */
char *client_fermer_session ();
