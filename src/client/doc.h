/**
 * \file doc.h
 *
 * \brief Commandes de documentation du client
 * 
 */

#ifndef __CLIENT_DOC_H__
#define __CLIENT_DOC_H__

/*!
 * \brief Affichage de la syntaxe du programme
 */
void
client_doc_syntaxe (char *progname);

/*!
 * \brief Affichage de la liste des commandes
 */
void
client_doc_commandes ();

/*!
 * \brief Affichage de la syntaxe d'ouverture de session
 */
void
client_doc_ouvrir ();

/*!
 * \brief Affichage de la syntaxe de fermeture de session
 */
void
client_doc_fermer ();

/*!
 * \brief Affichage de la syntaxe de l'emprunt de livre
 */
void client_doc_emprunt ();

/*!
 * \brief Affichage de la syntaxe de retour de livre
 */
void client_doc_retour ();

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void client_doc_livre ();

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void client_doc_auteur ();

/*!
 * \brief Affichage de la syntaxe de la consultation d'un adhérent
 */
void client_doc_adherent ();

/*!
 * \brief Affichage de la syntaxe de fermeture de session
 */
void client_doc_quitter ();

#endif
