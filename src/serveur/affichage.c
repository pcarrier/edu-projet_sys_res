#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

void
affiche_requete_informations (prot_requete_t op)
{
  switch (op.operation)
    {
    case (op_consulter_auteur):
      simple_affiche_requete ("consulter_auteur");
      break;
    case (op_consulter_titre):
      simple_affiche_requete ("consulter_titre");
      break;
    case (op_emprunter):
      simple_affiche_requete ("emprunter_livre");
      break;
    case (op_rendre):
      simple_affiche_requete ("rendre_livre");
      break;
    case (op_consulter_adherent):
      simple_affiche_requete ("consulter_adherents");
      break;
    case (op_ping):
      simple_affiche_requete ("ping");
      break;
    default:
      simple_affiche_requete ("operation inconnue");

    }
}


void
simple_affiche_requete (char *type)
{
  printf ("from %s : %s\n", "Distant", type);
}
