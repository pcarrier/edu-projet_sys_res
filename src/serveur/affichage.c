#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

void
affiche_requete_informations (prot_requete_t op)
{
  switch (op.operation)
    {
    case (op_consulter_auteur):
      simple_affiche ("consulter_auteur");
      break;
    case (op_consulter_titre):
      simple_affiche ("consulter_titre");
      break;
    case (op_emprunter):
      simple_affiche ("emprunter_livre");
      break;
    case (op_rendre):
      simple_affiche ("rendre_livre");
      break;
    case (op_consulter_adherent):
      simple_affiche ("consulter_adherents");
      break;
    case (op_ping):
      simple_affiche ("ping");
      break;
    default:
      simple_affiche ("operation inconnue");

    }
}


void
simple_affiche (char *type)
{
  printf ("from %s : %s\n", "Distant", type);
}
