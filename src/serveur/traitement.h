#ifndef __TRAIT_H_
#define __TRAIT_H_

/** 
 * Cette fonction remplit un tableau (le second paramètre passé)
 * en recherchant les occurences du premier paramètre dans le nom des livres
*/
void trait_consulter_titre(char * annuaire, char * nom_livre, livre_t * tab_result);

/** 
 * Cette fonction remplit un tableau (le second paramètre passé)
 * en recherchant ls occurances du premier paramètre dans les noms d'auteurs
 */
void trait_consulter_auteur(char * annuaire, char * nom_auteur, livre_t * tab_result);

#endif
