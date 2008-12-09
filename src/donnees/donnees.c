/****************************************************************

	Corps du module des données bdd.c
	Auteur: Dominique Vaufreydaz, Vincent Danjean

*****************************************************************/

#include <stdio.h>
#include "donnees.h"

/****************************************************************
    Fonction pour afficher les données relatives à un livre ou à un adhérent
*/
void
afficher_livre (livre_t l)
{
  printf ("Titre: %s\nAuteur(s): %s\n", l.titre, l.auteur);
  printf ("Nombre d'exemplaires : %u\n", l.livre_nbex);
  printf ("Exemplaires empruntés : %u\n", l.livre_nbemprunts);
  printf ("Exemplaires disponibles : %u\n\n", l.livre_dispos);
}

void
afficher_adherent (adherent_t a)
{
  int j;
  printf ("Prenom: %s\nNom: %s\n", a.prenom, a.nom);
  printf ("Nombre de prets : %u\n", a.nb_prets);
  for (j = 0; j < a.nb_prets; j++)
    printf ("    %s\n", a.prets[j]);
  printf ("\n");
}
