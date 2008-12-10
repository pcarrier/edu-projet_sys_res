#include "traitement.h"
#include <donnees/bdd.h>
#include <common.h>
#include <donnees/types.h>
#include <reseau/protocole.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


prot_ret_e
trait_consulter_titre(char * catalogue, char * nom_livre, livre_t * tab_result){
  //on bloque le fichier de lecture
  bdd_acces_lecture_debut();
  int retour = bdd_load_catalogue(catalogue);
  //on débloque le fichier de lecture
  bdd_acces_lecture_fin();
  
  if (retour == 0){
    int i;
    int j = 0;
    for (i = 0 ; i < cat_nb_livres ; i++){
      //on recherche la chaine de caractère reçue en paramètre parmis tous les noms de livres
      //si une occurence est trouvée, elle est rajoutée au tableau de résultat
      if (strstr (Catalogue[i].titre, nom_livre) != 0 ){
	tab_result[j] = Catalogue[i];
	j++;
      }
    }
    strcpy(tab_result[j].titre, "");

    if (j == 0){
      return ret_inexistant;
    }else{
      return ret_trouve;
    }
  }else{
    return ret_operation_impossible;
  }
  
}

prot_ret_e
trait_consulter_auteur(char * catalogue, char * nom_auteur, livre_t * tab_result){
  //on bloque le fichier de lecture
  bdd_acces_lecture_debut();
  int retour = bdd_load_catalogue(catalogue);
  //on débloque le fichier de lecture
  bdd_acces_lecture_fin();

  if (retour == 0){
    int i;
    int j = 0;
    for (i = 0; i < cat_nb_livres ; i++){
      //on recherche la chaine de caractère reçue en paramètre parmis tous les noms d'auteurs
      //si une occurence est trouvé, elle est rajoutée au tableau de résultat
      if ((strstr(Catalogue[i].auteur, nom_auteur) != 0) || (strstr(nom_auteur, Catalogue[i].auteur) != 0)){
	tab_result[j] = Catalogue[i];
	j++;
      }
    }
    strcpy(tab_result[j].titre, "");
    if (j == 0){
      return ret_inexistant;
    }else{
      return ret_trouve;
    }
  }else{
    return ret_operation_impossible;
  }
}

prot_ret_e
trait_consulter_adherent(char * annuaire, char * nom, adherent_t * tab_result){
	/*
  //on bloque le fichier de lecture
  bdd_acces_lecture_debut();
  int retour = bdd_load_annuaire(annuaire);
  //on débloque le fichier de lecture
  bdd_acces_lecture_fin();

  if (retour == 0){
    int i;
    int j = 0;
    for (i = 0 ; i < ann_nb_adhs ; i++){
      //on recherche la chaine de caractère reçue en paramètre parmis tous les nom d'adhérents
      //si une occurence est trouvée, elle est rajoutée au tablea de résultat
      if (strstr(Annuaire[i].nom, nom) != 0){
	tab_result[j] = Annuaire[i];
	j++;
      }
    }
    strcpy(tab_result[j].nom, "");
    if (j == 0){
      return ret_inexistant;
    }else{
      return ret_trouve;
    }
  }else{
    return ret_operation_impossible;
  }*/
}

prot_ret_e
trait_emprunter(char * annuaire, char * catalogue, char * params){
	/*
  char * nom_adh = params;
  char * nom_livre = params + strlen(nom_adh) + 1;

  //on bloque le fichier de lecture
  bdd_acces_lecture_debut();
  int retour_ann = bdd_load_annuaire(annuaire);
  int retour_cat = bdd_load_catalogue(catalogue);
  //on débloque le fichier de lecture
  bdd_acces_lecture_fin();

  if (retour_ann == 0 && retour_cat == 0){
    int i;
    for (i = 0; i < ann_nb_adhs; i++){
      if (Annuaire[i].titre == nom_livre){
	break;
      } 
    }

    int j;
    for (j = 0 ; j < cat_nb_livres ; j++){
      if (Catalogue[j].titre == nom_livre){
	break;
      }
    }
    int k = 0;
    while (k != PRETS_NBMAX){
      if (Annuaire[i].prets[k] == ""){
	break;
      }
      k++;
    }

    if (i == ann_nb_adhs || j == cat_nb_livres || Catalogue[j].livre_dispos){
      return ret_inexistant;
    }else{
      Annuaire[i].nb_prets++;
      Annuaire[i].prets[k] = nom_livre;
      Catalogue[j].livre_dispos--;
      Catalogue[j].livre_nbemprunts++;
      
      bdd_acces_ecriture_debut();
      int retour_sauv_ann = bdd_save_annuaire();
      int retour_sauv_cat = bdd_save_catalogue();
      bdd_acces_ecriture_fin();
     
      if (retour_sauv_ann == 0 && retour_sauv_cat == 0){
	return ret_trouve;
      }else{
	return ret_inexistant;
      }
    }
  }else{
    return ret_operation_impossible;
  }
  */
}
