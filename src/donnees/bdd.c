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
#include <gestion/gestionlivres.h>
#include <gestion/gestionadherents.h>

/****************************************************************
    Définition des variables conformément au fichier .h 
*/

/* Déclaration du catalogue contenant au maximum nb_max_livres */
livre_t Catalogue[nb_max_livres];

/* Variable contenant le nombre d'ouvrage courant dans le catalogue
   Cette valeur doit rester cohérente avec la capacité du catalogue */
int cat_nb_livres = 0;		/* par défault, aucun livre */

/* Déclaration de l'annuaire contenant au maximum nb_max_adherents */
adherent_t Annuaire[nb_max_adhs];

/* Variable contenant le nombre d'adhérents courant dans l'annuaire
   Cette valeur doit rester cohérente avec la capacité de l'annuaire */
int ann_nb_adhs = 0;		/* par défault, aucun adherent */

/****************************************************************
    Implémentation des fonctions du module
*/
/*Fonction de traitement du code de retour des fonctions d'acces aux fichiers.
 * Son header est donné ici et non dans le .h afin de cacher sa visibilité aux autres modules.
 */
void traiteRetour(ErreurAcces err, char * filename);


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
bdd_load_annuaire (char *annuaire)
{
  bdd_acces_lecture_debut ();
  int retAnnuaire = LireCatalogue (annuaire);
  bdd_acces_lecture_fin ();

  if (retAnnuaire < 0){
    traiteRetour(retAnnuaire,annuaire);
    return -1;
  }else{
    return 0;
  }
  bdd_acces_lecture_fin ();
}


/* Lecture des données du fichier catalogue
*/
int
bdd_load_catalogue (char *catalogue)
{
  bdd_acces_lecture_debut ();
  int retCatalogue = LireCatalogue (catalogue);
  bdd_acces_lecture_fin ();

  if (retCatalogue < 0){
    traiteRetour(retCatalogue, catalogue);
    return -1;
  }else{
    return 0;
  }
  bdd_acces_lecture_fin ();

}

/* Sauvegarde des données vers le fichier annuaire
 */

int
bdd_save_annuaire (char *annuaire)
{
  bdd_acces_ecriture_debut ();
  int retAnnuaire = EcrireAnnuaire (annuaire);
  bdd_acces_ecriture_fin ();

  if (retAnnuaire < 0){
    traiteRetour(retAnnuaire, annuaire);
    return -1;
  }else{
    return 0;
  }  

}


/* Sauvegarde des données vers le fichier catalogue
 */
int
bdd_save_catalogue (char *catalogue)
{
  bdd_acces_ecriture_debut ();
  int retCatalogue = EcrireCatalogue (catalogue);
  bdd_acces_ecriture_fin ();

  if (retCatalogue < 0){
    traiteRetour(retCatalogue, catalogue);
    return -1;
  }else{
    return 0;
  }
}

void traiteRetour(ErreurAcces err, char * filename){
	switch(err){
		case(ParametresIncorrects):
			printf("Paramètres incorrects lors de l'accès au fichier %s.\n",filename);
			break;
		case(OuvertureFichierImpossible):
			printf("Ouverture du fichier %s impossible.\n",filename);
			break;	
	}
}


