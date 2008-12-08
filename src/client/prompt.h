/*!
 * \file prompt.h
 * \brief Interactions à travers un prompt
 *
 * Saisie de commandes à travers GNU readline, et interprétation des résultats
 *
 */

/*!
 * \brief Obtenir une ligne à travers une invite de commande
 *
 * Récupère une ligne, la place dans l'historique et la renvoie.
 */
char *getline(char *prompt);
