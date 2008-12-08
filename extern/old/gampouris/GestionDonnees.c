// GestionDonnees.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestionLivres.h"
#include "GestionAdherents.h"

void
Usage (const char *NomProgramme)
{
	fprintf (stderr, "Usage de %s\n", NomProgramme);
	fprintf (stderr, 
	"Pour la création des fichiers catalogue 'mon_cat' et "
	"repertoire 'mon_rep'\n\t%s -c 'mon_cat' 'mon_rep'\n", NomProgramme);
	fprintf (stderr,
	"Pour la consultation des fichiers catalogue et repertoire \n"
	"\t%s -l 'mon_cat' 'mon_rep'\n", NomProgramme);
}

int
main (int argc, char *argv[])
{
	int CodeRetour;
	int i,j;
	
	/* Vérification des paramètres :
	   - nombre de paramètres ok
	   - le second est le debut d'une option
	   - le dernier n'est pas le début d'une option et n'est pas vide */
	
	if (argc != 4 || argv[1][0] != '-' || argv[2][0] == '-'
	    || argv[2][0] == '\0')
	{
		/* Usage affiche l'aide sur le programme */
		Usage (argv[0]);
		return 1;
	}
	
	if (!strcmp(argv[1],"-c")) {	/*creation catalogue*/
		strcpy (Catalogue[0].Titre, "Da Vinci Code");
		strcpy (Catalogue[0].Auteur, "Dan Brown, Daniel Roche");
		Catalogue[0].NombreExemplaires = 5;
		Catalogue[0].ExemplairesEmpruntes = 1;
		Catalogue[0].ExemplairesDisponibles = 4;
		NombreOuvragesAuCatalogue++;
				
		strcpy (Catalogue[1].Titre, "Moi, Bouddha");
		strcpy (Catalogue[1].Auteur, "José Fräches");
		Catalogue[1].NombreExemplaires = 1;
		Catalogue[1].ExemplairesEmpruntes = 0;
		Catalogue[1].ExemplairesDisponibles = 1;
		NombreOuvragesAuCatalogue++;
				
		strcpy (Catalogue[2].Titre,"Histoires inédites du Petit Nicolas");
		strcpy (Catalogue[2].Auteur, "René Goscinny, Sempé");
		Catalogue[2].NombreExemplaires = 2;
		Catalogue[2].ExemplairesEmpruntes = 0;
		Catalogue[2].ExemplairesDisponibles = 2;
		NombreOuvragesAuCatalogue++;
				
		strcpy (Catalogue[3].Titre, "Le Soleil des Scorta");
		strcpy (Catalogue[3].Auteur, "Laurent Gaudé");
		Catalogue[3].NombreExemplaires = 2;
		Catalogue[3].ExemplairesEmpruntes = 1;
		Catalogue[3].ExemplairesDisponibles = 1;
		NombreOuvragesAuCatalogue++;
				
		strcpy (Catalogue[4].Titre,"Un long dimanche de fiançailles");
		strcpy (Catalogue[4].Auteur, "Sébastien Japrisot");
		Catalogue[4].NombreExemplaires = 3;
		Catalogue[4].ExemplairesEmpruntes = 2;
		Catalogue[4].ExemplairesDisponibles = 1;
		NombreOuvragesAuCatalogue++;
				
		/* Ecriture dans le fichier */
		if (EcrireCatalogue (argv[2]) != 5) {
			fprintf (stderr,
					"Impossible d'initialiser le catalogue '%s'\n",
					argv[2]);
			return -1;
		}
		fprintf (stderr,
		"Catalogue '%s' initialisé avec 5 ouvrages\n",
		argv[2]);
		
		strcpy (Annuaire[0].Nom, "Martin");
		strcpy (Annuaire[0].Prenom, "Daniel");
		Annuaire[0].nbPrets = 1;
		strcpy (Annuaire[0].Prets[0],"Le Soleil des Scorta" );
		NombreAdherentsDansAnnuaire++;
				
		strcpy (Annuaire[1].Nom, "Vinoux");
		strcpy (Annuaire[1].Prenom, "Cyrille");
		Annuaire[1].nbPrets = 0;
		NombreAdherentsDansAnnuaire++;	
		
		strcpy (Annuaire[2].Nom, "Guillard");
		strcpy (Annuaire[2].Prenom, "Myriam");
		Annuaire[2].nbPrets = 2;
		strcpy (Annuaire[2].Prets[0],"Un long dimanche de fiançailles" );
		strcpy (Annuaire[2].Prets[1],"Da Vinci Code" );
		NombreAdherentsDansAnnuaire++;						
		/* Ecriture dans le fichier */
		if (EcrireAnnuaire (argv[3]) != 3) {
			fprintf (stderr,
			"Impossible d'initialiser le repertoire '%s'\n",
					argv[2]);
			return -1;
		}
		fprintf (stderr,
		"Annuaire '%s' initialisé avec 3 adhérents\n",
		argv[2]);

	/*----------------------------------------------------*/
	/* lecture catalogue */
	} else if (!strcmp(argv[1],"-l")) 	{
				
		/* On tente de lire le fichier demandÇ */
		CodeRetour = LireCatalogue (argv[2]);
		if (CodeRetour < 0) {
			/* Une erreur est survenue */
			switch (CodeRetour) {
				case ParametresIncorrects:
					fprintf (stderr,
		 "Paramätre '%s' invalide pour la fonction LireCatalogue\n",
					 argv[2]);
					return CodeRetour;
								
				case OuvertureFichierImpossible:
					fprintf (stderr,
		 "Impossible d'ouvrir le fichier '%s' en lecture\n",
					 argv[2]);
					return CodeRetour;
			}
		} else {
			if (CodeRetour == 0) {
				fprintf (stderr,
		 "Aucun livre dans le catalogue '%s'\n",
				argv[2]);
			} else {
				fprintf (stderr,
		 "%d livre(s) dans le catalogue '%s'\n\n",
				 CodeRetour, argv[2]);
				for (i = 0;i < NombreOuvragesAuCatalogue; i++) {
					fprintf (	stderr,
				"Titre: %s\nAuteur(s): %s\n",
						Catalogue[i].Titre,
						Catalogue[i].Auteur);
					fprintf (	stderr,
				"Nombre d'exemplaires : %u\n",
						Catalogue[i].
						NombreExemplaires);
					fprintf (	stderr,
				 "Exemplaires empruntÇs : %u\n",
						Catalogue[i].
						ExemplairesEmpruntes);
					fprintf (	stderr,
				 "Exemplaires disponibles : %u\n\n",
						Catalogue[i].
						ExemplairesDisponibles);
				}
			}
		}
		/*repertoire */
		CodeRetour = LireAnnuaire (argv[3]);
		if (CodeRetour < 0) {
			/* Une erreur est survenue */
			switch (CodeRetour) {
				case ParametresIncorrects:
					fprintf (stderr,
		 "Paramätre '%s' invalide pour la fonction LireAnnuaire\n",
					 argv[2]);
					return CodeRetour;
								
				case OuvertureFichierImpossible:
					fprintf (stderr,
		 "Impossible d'ouvrir le fichier '%s' en lecture\n",
					 argv[2]);
					return CodeRetour;
			}
		} else {
			if (CodeRetour == 0) {
					fprintf (stderr,
				 "Aucun adhérent dans le répertoire '%s'\n",
					argv[2]);
			} else {
				fprintf (stderr,
				 "%d adherents(s) dans le catalogue '%s'\n\n",
					 CodeRetour, argv[2]);
				for (i = 0;i < NombreAdherentsDansAnnuaire; i++) {
					fprintf (	stderr,
						"Prenom: %s\nNom: %s\n",
						Annuaire[i].Prenom,
						Annuaire[i].Nom);
					fprintf (	stderr,
						"Nombre de prets : %u\n",
						 Annuaire[i].nbPrets);
					for (j =0; j< Annuaire[i].nbPrets; j++)
						fprintf (	stderr,
							"    %s\n",
							 Annuaire[i].Prets[j]);
						fprintf(stderr,"\n");
					}
			}
		}

	
	} else	Usage (argv[0]);
					
	return 0;
}
