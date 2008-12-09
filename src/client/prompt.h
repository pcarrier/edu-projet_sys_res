/*!
 * \file prompt.h
 * \brief Interactions à travers une invite de commandes
 *
 * Saisie de commandes à travers GNU readline puis parsage
 *
 */

#ifndef __PROMPT_H__
#define __PROMPT_H__

/*!
 * \brief Obtenir une ligne à travers une invite de commande
 *
 * Récupère une ligne, la place dans l'historique et la renvoie.
 */
char *getline (char *prompt);

#endif
