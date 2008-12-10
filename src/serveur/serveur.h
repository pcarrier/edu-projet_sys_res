#ifndef __SERVER_H_
#define __SERVER_H_
#include <stdlib.h>
#include <stdio.h>
/**
 * Affiche l'aide sur les paramètres à donner au serveur l'ors du démarage.
 */
void serveur_doc_syntaxe (char *prorgamme);
typedef struct
{
  char *  fichierAnnuaire;
  char  * fichierCatalogue;
} dbfiles;
#endif
