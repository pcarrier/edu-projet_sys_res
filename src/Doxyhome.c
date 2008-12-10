/*!
 * \file Doxyhome.c
 *
 * \brief Page d'accueil de la documentation
 *
 *
 * \mainpage
 *
 * \section Choix de conception
 *
 * \subsection Interactions côté client
 *
 * Nous avons choisi d'utiliser une interaction en ligne de commande avec
 * historique, notamment pour faciliter la conception de tests automatisés.
 * Nous utilisons pour cela la librairie readline.
 * La complétion pourrait être une fonctionnalité intéressante mais nous
 * avons choisi d'autres priorités.
 *
 * \section Méthode de travail
 *
 * \subsection Répartition des tâches
 *
 * Nous avons travaillé la majorité du temps en binôme par problématique,
 * en travaillant dans le même lieu pour maximiser les interactions.
 *
 * \subsection Travail collaboratif
 *
 * Nous avons décidé de travailler simultanément sur le code.
 * Pour simplifier la sauvegarde, la mutualisation des contributions, etc.
 * nous nous sommes reposés sur l'outil git.
 * Un dépôt est visible sur
 * http://github.com/jcsaaddupuy/projet_sys_res/network
 *
 * \subsection Documentation
 *
 * Nous avons choisi d'automatiser la génération de documentation à l'aide
 * de doxygen. Nous n'avons pas pris le temps d'adapter tous les commentaires
 * du code fourni à la syntaxe de cet outil.
 *
 * \subsection Normes de présentation
 *
 * Nous avons massivement utilisé GNU indent sur le code pour en assurer la
 * lisibilité, et avons effectué de nombreux remaniement de code à l'aide
 * d'expressions régulières pour adopter des notations systématiques (macros,
 * constantes du préprocesseur, fonctions, etc.).
 * \section Audit
 *
 * \subsection Jeux de test
 *
 * On effectue de nombreux tests
 *
 * \subsection Fuites mémoires
 *
 * Visiblement aucune côté client.
 * Le seul problème identifié après étude dans Valgrind sur des milliers
 * de commandes concerne l'historique de readline.
 *
 * \section Défauts
 *
 * Les données transmises ne sont pas initialisées, donc une quantité
 * considérable de mémoire non-initialisée est envoyée au client
 * (ce problème pourrait rapidement être résolu).
 *
 * On n'examine pas le statut connecté/déconnecté en TCP.
 * 
 * La réponse "pong" est traitée comme une réussite quelle que soit la requête.
 *
 */
