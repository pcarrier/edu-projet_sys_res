/****************************************************************

	Corps du module des données BdD.c
	Auteur: Dominique Vaufreydaz, Vincent Danjean

*****************************************************************/

#include <stdio.h>
#include "donnees.h"

/****************************************************************
    Fonction pour afficher les données relatives à un livre ou à un adhérent
*/
void AfficherLivre(Livre l)
{
	printf("Titre: %s\nAuteur(s): %s\n", l.Titre, l.Auteur);
	printf("Nombre d'exemplaires : %u\n", l.NombreExemplaires);
	printf("Exemplaires empruntés : %u\n", l.ExemplairesEmpruntes);
	printf("Exemplaires disponibles : %u\n\n", l.ExemplairesDisponibles);
}

void AfficherAdherent(Adherent a)
{
	int j;
	printf("Prenom: %s\nNom: %s\n", a.Prenom, a.Nom);
	printf("Nombre de prets : %u\n", a.nbPrets);
	for (j = 0; j < a.nbPrets; j++)
		printf("    %s\n", a.Prets[j]);
	printf("\n");
}
