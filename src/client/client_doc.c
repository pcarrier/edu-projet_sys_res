#include <stdio.h>

void
client_doc_syntaxe (char *progname)
{
  fprintf (stderr, "Usage: %s [-p port] [-t] [host]\n"
	   "  -p port: utiliser le port p plutot que " PORT_DEFAUT "\n",
	   "  -u: utiliser TCP plutot que UDP ;\n",
	   "  host: hote a utiliser au lieu de " SERVEUR_DEFAUT "\n",
	   progname);
}

/*!
 * \brief Affichage de la liste des commandes
 */
void
client_doc_commandes ()
{
  fprintf (stdout, "[Commandes disponibles]\n"
	   "  ouvrir, fermer, titre, auteur, emprunter, rendre, adherent, quitter\n");
}

/*!
 * \brief Affichage de la syntaxe d'ouverture de session
 */
void
client_doc_ouvrir ()
{
  fprintf (stdout, "[ouvrir]\n" "  Bonne question ! Rien dans la doc...\n");
}

/*!
 * \brief Affichage de la syntaxe de fermeture de session
 */
void
client_doc_fermer ()
{
  fprintf (stdout, "[fermer]\n"
	   "  Usage: fermer\n" "  Ferme la session en cours\n");
}

/*!
 * \brief Affichage de la syntaxe de l'emprunt de livre
 */
void
client_doc_emprunt ()
{
  fprintf (stdout, "[emprunter]\n"
	   "  Usage : emprunter a l\n"
	   "  L'adhérent de référence 'a' emprunte le livre de référence 'l'.\n");
}

/*!
 * \brief Affichage de la syntaxe de retour de livre
 */
void
client_doc_retour ()
{
  fprintf (stdout, "[retour]\n"
	   "  Usage: retour a l\n"
	   "  L'adhérent de référence 'a' retourne le livre de référence 'l'.\n");
}

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void
client_doc_livre ()
{
  fprintf (stdout, "[titre]\n"
	   "  Usage: titre t\n"
	   "  Affiche les informations sur livre de titre 't'.\n");
}

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void
client_doc_auteur ()
{
  fprintf (stdout, "[auteur]\n"
	   "  Usage: auteur a\n"
	   "  Liste les titres dont l'auteur a pour nom 'a'.\n");
}

/*!
 * \brief Affichage de la syntaxe de la consultation d'un adhérent
 */
void
client_doc_adherent ()
{
  fprintf (stdout, "[adherent]\n"
	   "  Usage: adherent a\n"
	   "  Affiche les informations sur l'adhérent ayant pour nom 'a'.\n");
}

/*!
 * \brief Affichage de la syntaxe de fermeture de session
 */
void
client_doc_quitter ()
{
  fprintf (stdout, "[quitter]\n"
	   "  Usage: quitter\n" "  Quitte le logiciel\n");
}
