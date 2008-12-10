#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

void
affiche_requete_informations (prot_requete_t op)
{
  switch (op.operation)
    {
    case (op_consulter_auteur):
      simple_affiche_requete ("consulter_auteur", op.param);
      break;
    case (op_consulter_titre):
      simple_affiche_requete ("consulter_titre", op.param);
      break;
    case (op_emprunter):
      simple_affiche_requete ("emprunter_livre",op.param);
      break;
    case (op_rendre):
      simple_affiche_requete ("rendre_livre",op.param);
      break;
    case (op_consulter_adherent):
      simple_affiche_requete ("consulter_adherents", op.param);
      break;
    case (op_ping):
      simple_affiche_requete ("ping",NULL);
      break;
    default:
      simple_affiche_requete ("operation inconnue", op.param);

    }
}


void
simple_affiche_requete (char *type, char * param)
{
	if (param != NULL){
	       	printf ("from %s : %s %s\n", "Distant", type, param);
	}else{
	       	printf ("from %s : %s\n", "Distant", type);	
	}
}

void affiche_requete_status(prot_ret_e status){
	switch(status){
		case(ret_operation_impossible):
			printf("Opération impossible\n");
			break;
		case(ret_inexistant):
			printf("Aucun résultat trouvé\n");
			break;
		case(ret_succes):
			printf("Trouvé\n");
			break;
		case(ret_pong):
			printf("Pong\n");
			break;
		default:
			printf("Status inconnu...something's wrong.\n");

	}

}
