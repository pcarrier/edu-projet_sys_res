#ifndef __AFFICHAGE_H_
#define __AFFICHAGE_H_
#include <reseau/protocole.h>
/**
 * \brief{Affiche à l'écran les informations sur les requètes entrantes
 * en fonction de leurs type.}
 */
void affiche_requete_informations (prot_requete_t op);

/**
 * \brief Affichage standardisé pour chaque requête.
 * Le paramètre type est une chaine de caractère représantant le nom
 * de l'opération recue ("consulter_auteur", "consulter_titre",...) 
 */
void simple_affiche_requete (char *type, char * param);

void affiche_requete_status(prot_ret_e status);
#endif
