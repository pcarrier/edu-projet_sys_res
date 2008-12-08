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
  printf ("Titre: %s\nAuteur(s): %s\n", l.Titre, l.Auteur);
  printf ("Nombre d'exemplaires : %u\n", l.livre_nbex);
  printf ("Exemplaires empruntés : %u\n", l.livre_nbemprunts);
  printf ("Exemplaires disponibles : %u\n\n", l.livre_dispos);
}

void
afficher_adherent (adherent_t a)
{
  int j;
  printf ("Prenom: %s\nNom: %s\n", a.Prenom, a.Nom);
  printf ("Nombre de prets : %u\n", a.nbPrets);
  for (j = 0; j < a.nbPrets; j++)
    printf ("    %s\n", a.Prets[j]);
  printf ("\n");
}
