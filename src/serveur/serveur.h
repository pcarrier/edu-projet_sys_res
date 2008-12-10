#ifndef __SERVER_H__
#define __SERVER_H__
#include <reseau/protocole.h>

/**
 * Affiche l'aide sur les paramètres à donner au serveur lors du démarage.
 */
void serveur_doc_syntaxe (char *programme);

typedef struct
{
  char *fichier_annuaire;
  char *fichier_catalogue;
} db_files_t;


prot_ret_e traite_requete (prot_requete_t rqt_client,
			   prot_reponse_t * rep_client);
#endif
