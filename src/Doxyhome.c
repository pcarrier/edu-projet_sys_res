/*!
 * \file Doxyhome.c
 *
 * \brief Page d'accueil de la documentation
 *
 *
 * \mainpage
 *
 * \section choix Choix de conception
 *
 * \subsection requetes Gestion des requêtes côté serveur
 *
 * On duplique le processus serveur aux demandes de connexion en TCP et
 * à la réception d'une requête en UDP. Le pool de processus fils n'est
 * pas implémenté faute de temps.
 *
 * \subsection prompt Interactions côté client
 *
 * Nous avons choisi d'utiliser une interaction en ligne de commande avec
 * historique, notamment pour faciliter la conception de tests automatisés.
 * Nous utilisons pour cela la librairie readline.
 * La complétion pourrait être une fonctionnalité intéressante mais nous
 * avons choisi d'autres priorités.
 *
 * \subsection params Paramètrage de l'application
 *
 * Nous utilisons getopt() pour disponiser d'arguments simples, préfixés et
 * d'un commutateur.
 *
 * \section methodologie Méthode de travail
 *
 * \subsection repartition Répartition des tâches
 *
 * Nous avons travaillé la majorité du temps en binôme par problématique,
 * en travaillant dans le même lieu pour maximiser les interactions.
 * Nous avons commencé par découper le travail entre BDD (Mickael et Christo)
 * et réseau (Jean-Christophe et Geoffroy) puis entre serveur (Jean-Christophe
 * et Mickael) et client (Christo et Geoffroy).
 *
 * \subsection collaboration Travail collaboratif
 *
 * Nous avons décidé de travailler simultanément sur le code.
 * Pour simplifier la sauvegarde, la mutualisation des contributions, etc.
 * nous nous sommes reposés sur l'outil git.
 * Un dépôt est visible sur
 * http://github.com/jcsaaddupuy/projet_sys_res/network
 *
 * \subsection doc Documentation
 *
 * Nous avons choisi d'automatiser la génération de documentation à l'aide
 * de doxygen. Nous n'avons pas pris le temps d'adapter tous les commentaires
 * du code fourni à la syntaxe de cet outil.
 *
 * \subsection indent Normes de présentation
 *
 * Nous avons massivement utilisé GNU indent sur le code pour en assurer la
 * lisibilité, et avons effectué de nombreux remaniement de code à l'aide
 * d'expressions régulières pour adopter des notations systématiques (macros,
 * constantes du préprocesseur, fonctions, etc.).
 *
 * \section audit Audit
 *
 * \subsection tests Jeux de test
 *
 * On effectue divers tests à l'aide de fichiers d'instruction.
 *
 * \subsection fuites Fuites mémoires
 *
 * Visiblement aucune côté client.
 * Le seul problème identifié après étude dans Valgrind sur des milliers
 * de commandes concerne l'historique de readline.
 *
 * \section defauts Défauts
 *
 * Les données transmises ne sont pas initialisées, donc une quantité
 * considérable de mémoire non-initialisée est envoyée au client
 * (ce problème pourrait rapidement être résolu).
 *
 * Les déconnexions et erreurs de transmission sont gérées de façon insuffisante,
 * on gagnerait à compléter fon.c à cette fin.
 *
 * On utilise des énumérations pour les types d'opérations et codes de retour,
 * qui sont donc des entiers. Le protocole dépend donc de la plateforme utilisée
 * (taille des entiers, boutisme). Nous ne corrigerons pas ce problème faute de
 * temps.
 * 
 * La réponse "pong" est traitée comme une réussite quelle que soit la requête au
 * niveau du client.
 *
 * \subsection lourd Lourdeur du protocole
 *
 * Le protocole transmet systématiquement d'énormes structures, quelle que soit
 * la quantité d'informations à transmettre. On gagnerait à transmettre l'opération
 * ou le code de retour dans un entier, puis le paramètre jusqu'au '\0' pour les
 * requêtes, la taille des résultats suivie de chaque résultat sous la forme
 * valeur '\0' valeur '\0' .. valeur "\0" (par exemple) pour les réponses.
 *
 */
