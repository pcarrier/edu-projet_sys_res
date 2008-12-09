#include "traitement.h"
#include <donnees/bdd.h>
#include <common.h>
#include <donnees/types.h>
#include <reseau/protocole.h>

void
trait_consulter_titre(char * nom_livre, livre_t * tab_result){
  //on bloque le fichier de lecture
  bdd_acces_lecture_debut();
  bdd_load_catalogue();
  //on débloque le fichier de lecture
  bdd_acces_lecture_fin();
  int j = 0;

  for (int i = 0 ; i < cat_nb_livre ; i++){
    //on recherche la chaine de caractère reçue en paramètre parmis tous les noms de livres
    //si une occurence est trouvée, elle est rajoutée au tableau de résultat
    if (strcasestr (Catalogue[i].titre, nom_livre) != NULL){
      tab_result[j] = Catalogue[i];
      j++;
    }
  }
}

void
trait_consulter_auteur(char * nom_auteur, livre_t * tab_result){
  //on bloque le fichier de lecture
  bdd_acces_lecture_debut();
  bdd_acces_catalogue();
  //on débloque le fichier de lecture
  bdd_acces_lecture_fin();
  int j = 0;
  
  for (int i = 0 ; i < cat_nb_livre ; i++){
    //on recherche la chaine de caractère reçue en paramètre parmis tous les noms d'auteurs
    //si une occurence est trouvé, elle est rajoutée au tableau de résultat
    if ((strcasestr(Catalogue[i].auteur, nom_auteur) != NULL) || (strcasestr(nom_auteur, Catalogue[i].auteur) != NULL)){
      tab_result[j];
      j++;
    }
  }
}
