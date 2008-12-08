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
void client_doc_emprunt ();

/*!
 * \brief Affichage de la syntaxe de retour de livre
 */
void client_doc_retour ();

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void client_doc_livre ();

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void client_doc_auteur ();

/*!
 * \brief Affichage de la syntaxe de la consultation d'un adhérent
 */
void client_doc_adherent ();

/*!
 * \brief Affichage de la syntaxe de fermeture de session
 */
void client_doc_quitter ();
