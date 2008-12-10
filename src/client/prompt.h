/*!
 * \file prompt.h
 * \brief Interactions à travers une invite de commandes
 *
 * Saisie de commandes à travers GNU readline et aide au parsing
 *
 */

#ifndef __PROMPT_H__
#define __PROMPT_H__

/*!
 * \brief Obtenir une ligne à travers une invite de commande
 *
 * Récupère une ligne, la place dans l'historique et la renvoie.
 */
char *lire_ligne (char *prompt);

/*!
 * \brief Formate l'invite de commande
 *
 * Affiche l'hôte, le port et le protocole.
 *
 */
void fancy_prompt ();

/*!
 * \brief Lire une commande
 *
 * Formate l'invite de commande puis retourne une ligne obtenue avec ce prompt
 *
 */
char *lire_commande ();

/*!
 * \brief Récupérer le premier token
 *
 * Sépare la chaîne en placant un caractère de fin au premier espace trouvé,
 * retourne la position suivante.
 *
 */
char *extraire_parametre (char *c);


#endif
