#include <stdio.h>
#include <common.h>

void
client_doc_syntaxe (char *progname)
{
  fprintf (stderr, "Usage: %s [-p port] [-t] [host]\n"
	   "  host: hote a utiliser au lieu de " SERVEUR_DEFAUT "\n"
	   "  -t: utiliser TCP plutot que UDP ;\n"
	   "  -p port: utiliser le port p plutot que " PORT_DEFAUT "\n",
	   progname);
}

void
client_doc_commandes ()
{
  fprintf (stdout, "[Commandes disponibles]\n"
	   "  aide, ouvrir, fermer, titre, auteur, emprunter, rendre, adherent, quitter\n"
	   "\nVoir aide aide\n");
}

void
client_doc_aide ()
{
  fprintf (stdout, "[aide]\n"
	   "  Usage: aide [c]\n"
	   "  Affiche cette aide ou l'aide de la commande de nom c si précisée.\n");
}

void
client_doc_ouvrir ()
{
  fprintf (stdout, "[ouvrir]\n" "  Bonne question ! Rien dans la doc...\n");
}

void
client_doc_fermer ()
{
  fprintf (stdout, "[fermer]\n"
	   "  Usage: fermer\n" "  Ferme la session en cours\n");
}

void
client_doc_emprunter ()
{
  fprintf (stdout, "[emprunter]\n"
	   "  Usage: emprunter a l\n"
	   "  L'adhérent de nom 'a' emprunte le livre de titre 'l'.\n");
}

void
client_doc_rendre ()
{
  fprintf (stdout, "[retour]\n"
	   "  Usage: retour a l\n"
	   "  L'adhérent de nom 'a' retourne le livre de titre 'l'.\n");
}

void
client_doc_titre ()
{
  fprintf (stdout, "[titre]\n"
	   "  Usage: titre t\n"
	   "  Affiche les informations sur les livres dont le titre contient 't'.\n");
}

void
client_doc_auteur ()
{
  fprintf (stdout, "[auteur]\n"
	   "  Usage: auteur a\n"
	   "  Affiche les informations sur les livres dont l'auteur a un nom contenant 'a'.\n");
}

void
client_doc_adherent ()
{
  fprintf (stdout, "[adherent]\n"
	   "  Usage: adherent a\n"
	   "  Affiche les informations sur les adhérents dont le nom contient 'a'.\n");
}

void
client_doc_quitter ()
{
  fprintf (stdout, "[quitter]\n"
	   "  Usage: quitter\n" "  Quitte le logiciel\n");
}
