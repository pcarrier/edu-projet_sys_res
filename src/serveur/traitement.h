#ifndef __TRAIT_H__
#define __TRAIT_H__

#include <reseau/protocole.h>

/** 
 * Cette fonction remplit un tableau (le dernier paramètre passé)
 * en recherchant les occurences du second paramètre dans le nom des livres.
 * Retourne un code prédéfini en fonction de la réussite ou du type d'échec.
*/
prot_ret_e trait_consulter_titre (char *catalogue, char *nom_livre,
				  livre_t * tab_result);

/** 
 * Cette fonction remplit un tableau (le dernier paramètre passé)
 * en recherchant les occurences du second paramètre dans les noms d'auteurs
 * Retourne un code prédéfini en fonction de la réussite ou du type d'échec.
 */
prot_ret_e trait_consulter_auteur (char *catalogue, char *nom_auteur,
				   livre_t * tab_result);

/** 
 * Cette fonction remplit un tableau (le dernier paramètre passé)
 * en recherchant les occurences du second paramètre dans les noms d'adhérents.
 * Retourne un code préféni en fonction de le réussite ou du type d'échec
 */
prot_ret_e trait_consulter_adherent (char *annuaire, char *nom,
				     adherent_t * tab_result);

/** 
 * Cette fonction lit puis écrit dans les fichiers d'annuaire et de catalogue
 * en fonction des deux parties de la chaine params passée en dernier paramètre
 */
prot_ret_e trait_emprunter (char *annuaire, char *catalogue, char *params);

/** 
 * Cette fonction lit puis écrit dans les fichiers d'annuaire et de catalogue
 * en fonction des deux parties de la chaine params passée en dernier paramètre
 */
prot_ret_e trait_rendre (char *annuaire, char *catalogue, char *params);

#endif
