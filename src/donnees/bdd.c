/****************************************************************

	Corps du module des données bdd.c
	Auteur: Dominique Vaufreydaz, Vincent Danjean

*****************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include "bdd.h"
#include <common.h>

/****************************************************************
    Définition des variables conformément au fichier .h 
*/

/* Déclaration du catalogue contenant au maximum nb_max_livres */
livre_t Catalogue[nb_max_livres];

/* Variable contenant le nombre d'ouvrage courant dans le catalogue
   Cette valeur doit rester cohérente avec la capacité du catalogue */
int cat_nb_livres = 0;	/* par défault, aucun livre */

/* Déclaration de l'annuaire contenant au maximum nb_max_adherents */
adherent_t Annuaire[nb_max_adhs];

/* Variable contenant le nombre d'adhérents courant dans l'annuaire
   Cette valeur doit rester cohérente avec la capacité de l'annuaire */
int ann_nb_adhs = 0;	/* par défault, aucun adherent */

/****************************************************************
    Implémentation des fonctions du module
*/


#define LOCK_FILENAME "serveur.lock"

static int lock_fd = -1;

void
bdd_acces_lecture_debut ()
{
  lock_fd = open (LOCK_FILENAME, O_RDONLY | O_CREAT, S_IRUSR);
  if (-1 == lock_fd)
    {
      perror ("Unable to open " LOCK_FILENAME);
      return;
    }
  flock (lock_fd, LOCK_SH);
}

void
bdd_acces_lecture_fin ()
{
  if (-1 == lock_fd)
    {
      return;
    }
  flock (lock_fd, LOCK_UN);
  close (lock_fd);
  lock_fd = -1;
}

void
bdd_acces_ecriture_debut ()
{
  lock_fd = open (LOCK_FILENAME, O_RDONLY | O_CREAT, S_IRUSR);
  if (-1 == lock_fd)
    {
      perror ("Unable to open " LOCK_FILENAME);
      return;
    }
  flock (lock_fd, LOCK_EX);
}

void
bdd_acces_ecriture_fin ()
{
  if (-1 == lock_fd)
    {
      return;
    }
  flock (lock_fd, LOCK_UN);
  close (lock_fd);
  lock_fd = -1;
}

/* Lecture des données depuis le ou les fichiers vers la mémoire
   (ie vers les tableaux Catalogue et Annuaire ainsi que vers les
   variables globales cat_nb_livres et
   ann_nb_adhs)
*/
int
bdd_load (char * annuaire, char * catalogue){
  int retAnnuaire = bdd_load_annuaire(annuaire);
  int retCatalogue = bdd_load_catalogue(catalogue);

  return retAnnuaire + retCatalogue;
 
}


int
bdd_load_annuaire (char * annuaire)
{
  bdd_acces_lecture_debut();
  FILE * file=fopen(annuaire,"r");

  if (file == NULL){
    return RErrAnn;
  }

  int nbItemLu = fread(&Annuaire, sizeof(Annuaire) , ann_nb_adhs, file);

  fclose(file);
  bdd_acces_lecture_fin();
  printf ("Fichier Chargé\n");

  return 0;
}




int
bdd_load_catalogue (char * catalogue)
{
  bdd_acces_lecture_debut();
  FILE * file=fopen(catalogue,"r");

  if (file == NULL){
    return RErrCat;
  }

  int nbItemLu = fread(&Catalogue, sizeof(Catalogue) , cat_nb_livres, file);

  fclose(file);
  bdd_acces_lecture_fin();
  printf ("Fichier Chargé\n");

  return 0;
}

/* Sauvegarde des données depuis la mémoire vers le ou les fichiers
*/

int
bdd_save(char * annuaire, char * catalogue){
  int retAnnuaire = bdd_save_annuaire(annuaire);
  int retCatalogue = bdd_save_catalogue(catalogue);

  return retAnnuaire + retCatalogue;
}

int
bdd_save_annuaire (char * annuaire)
{
  bdd_acces_ecriture_debut();
  FILE * file=fopen(annuaire,"w+b");

  int nbItemEcrits = fwrite(&Annuaire, sizeof(Annuaire) , ann_nb_adhs, file);

  fclose(file);
  bdd_acces_ecriture_fin();
  printf ("Fichié Sauvegardé\n");
  
  
  if (nbItemEcrits != ann_nb_adhs){
    printf("nbItemsEcrits : %i\n",nbItemEcrits);
    return WErrAnn;
  }else{
    return 0;
  }
}


int
bdd_save_catalogue (char * catalogue){
  bdd_acces_ecriture_debut();
  FILE * file=fopen(catalogue,"w+b");

  int nbItemE = fwrite(&Catalogue, sizeof(Catalogue), cat_nb_livres, file);

  fclose(file);
  bdd_acces_ecriture_fin();
  printf ("Fichier Sauvegardé\n");

  if (nbItemE != cat_nb_livres){
  	printf("nbItemsE : %i, cat_nb_livres:%i \n",nbItemE, cat_nb_livres);
	return WErrCat;
  }else{
    return 0;
  }
}
