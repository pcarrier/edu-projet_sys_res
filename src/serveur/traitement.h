#ifndef __TRAIT_H_
#define __TRAIT_H_

/** 
 * Cette fonction remplit un tableau (le second paramètre passé)
 * en recherchant les occurences du premier paramètre dans le nom des livres.
 * Retourne un code prédéfini en fonction de la réussite ou du type d'échec.
*/
prot_ret_e trait_consulter_titre(char * catalogue, char * nom_livre, livre_t * tab_result);

/** 
 * Cette fonction remplit un tableau (le second paramètre passé)
 * en recherchant ls occurances du premier paramètre dans les noms d'auteurs
 * Retourne un code prédéfini en fonction de la réussite ou du type d'échec.
 */
prot_ret_e trait_consulter_auteur(char * catalogue, char * nom_auteur, livre_t * tab_result);

#endif
