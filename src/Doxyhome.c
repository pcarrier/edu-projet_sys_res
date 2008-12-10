/*!
 * \file Doxyhome.c
 *
 * \brief Page d'accueil de la documentation
 *
 *
 * \mainpage
 *
 * \section avancement Avancement
 *
 * \subsection etat État actuel du projet
 *
 * Sauf erreur de notre part, l'ensemble des fonctionnalités demandées
 * ont été implémentées, de même que le support de l'UDP, l'affichage
 * côté client des temps de requête.
 * 
 * \subsection difficultes Difficultés rencontrées
 *
 * Nous n'avons découvert que mardi midi les corrections proposées par
 * les enseignants, et avons donc perdu du temps lundi sur des
 * dysfonctionnements liés notamment aux duplications de code.
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
 * \subsection planning Planning
 *
 * Nous souhaitions répondre au cahier des charges de base mardi soir,
 * après nous être d'abord focalisés sur la gestion des données,
 * puis les interactions client-serveur, afin de consacrer le temps restant
 * à l'UDP et à l'utilisation d'un pool de serveur.
 * Ces objectifs ont été réalisés à l'exception du pool.
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
 * du code fourni à la syntaxe de cet outil, ni d'écrire beaucoup de commentaires
 * pour notre code. Cependant, nous le considérons comme facilement analysable
 * à l'heure actuelle.
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
 * Quelques fonctions et constantes fournies ne sont plus utilisées.
 * Nous n'avons pas pris le temps de tout nettoyer.
 *
 * Les données transmises ne sont pas initialisées, donc une quantité
 * considérable de mémoire non-initialisée est envoyée au client
 * (ce problème pourrait rapidement être résolu).
 *
 * Les déconnexion et erreurs de transmission sont gérées de façon insuffisante,
 * on gagnerait à compléter fon.c à cette fin. De plus, la consistance des
 * informations transmises est insuffisamment vérifiée (en cas d'erreur sur le
 * serveur, on observe des segfaults).
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
 * ou le code de retour dans un entier, puis le paramètre jusqu'au \'\0\' pour les
 * requêtes, la taille des résultats suivie de chaque résultat sous la forme
 * valeur '\\0' valeur '\\0' ... valeur "\0" (par exemple) pour les réponses.
 *
 */
