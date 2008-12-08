#include <stdio.h>

void
client_doc_syntaxe (char *progname)
{
  fprintf (stderr, "Usage: %s [-p port] [-P (tcp|udp)] host\n", progname);
}

/*!
 * \brief Affichage de la liste des commandes
 */
void
client_doc_commandes ()
{
  fprintf (stdout, "[Commandes disponibles]\n"
	   "  ouvrir, fermer, titre, auteur, emprunter, rendre, quitter\n");
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
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void
client_doc_livre ()
{
  fprintf (stdout, "[titre]\n"
	   "  Usage: titre t\n"
	   "  Affiche les informations du livre de titre 't'.\n");
}

/*!
 * \brief Affichage de la syntaxe de la consultation d'auteur
 */
void
client_doc_auteur ()
{
  fprintf (stdout, "[auteur]\n"
	   "  Usage: auteur a\n"
	   "  Liste les titres ayant pour auteur 'a'.\n");


/*!
 * \brief Affichage de la syntaxe de retour de livre
 */
  void client_doc_retour ()
  {
    fprintf (stdout, "[retour]\n" "  Usage: ");

/*!
 * \brief Affichage de la syntaxe de la consultation d'un adhérent
 */
    void client_doc_adherent ();


/*!
 * \brief Affichage de la syntaxe d'ouverture de session
 */
    void client_doc_session ()
    {
      return;
    }
