#include <stdio.h>

void client_doc_syntaxe(char *name) {
  fprintf(stderr,"Usage: %s [-p port] [-P (tcp|udp)] host\n",argv[0]);
}

/*!
 * \brief Affichage de la liste des commandes
 */
void client_doc_commandes();

/*!
 * \brief Affichage de la syntaxe de la commande d'ouverture de session
 */
void client_doc_emprunt();

/*!
 * \brief Affichage de la syntaxe de l'emprunt de livre
 */
void client_doc_emprunt();

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void client_doc_titre();

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void client_doc_auteur();

/*!
 * \brief Affichage de la syntaxe de retour de livre
 */
void client_doc_retour();

/*!
 * \brief Affichage de la syntaxe de la consultation d'un adhérent
 */
void client_doc_adherent();


/*!
 * \brief Affichage de la syntaxe d'ouverture de session
 */
void client_doc_session();

/*!
 * \brief Affichage de la syntaxe de fermeture de session
 */

void client_doc_fermeture();
