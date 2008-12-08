PROGS=gestiondonnees.bin client.bin serveur.bin

SOURCES_client=reseau/fon.c client/client.c client/client_doc.c client/interface_client.c client/prompt.c donnees/donnees.c
SOURCES_serveur=reseau/fon.c serveur/serveur.c donnees/bdd.c
SOURCES_GestionDonnees=donnees/bdd.c donnees/donnees.c gestion/gestiondonnees.c

SOURCES=$(SOURCES_client) $(SOURCES_serveur) $(SOURCES_projet)

# On stocke dans SYSTEM le résultat de la commande 'uname -s'
# Il faut les deux lignes dans cet ordre pour que ça marche aussi bien avec le make de Solaris que celui de Linux
SYSTEM = $(shell uname -s)
SYSTEM:sh = uname -s

# Options de compilation (à commenter ou pas suivant ce qu'on veut)
# On garde les informations de débogage
CFLAGS += -g
# Optimisation du code par le compilateur
CFLAGS += -O2
# DÈtection d'un maximum d'erreurs
CFLAGS += -Wall
# On ne crée pas le programme tant qu'il y a des erreurs
#CFLAGS += -Werror
# On fait tout d'ici...
CFLAGS += -I.

# Si la ligne suivante est décommentée, du code de debug est compilé
# dans fon.c. Il permet d'observer les messages.
CPPFLAGS += -DDEBUG

# Permet de compiler la solution (enseignants seulement)
CPPFLAGS += -DSOLUTION

# Compilateur à utiliser
CC=gcc

# Bibliothèques à utiliser
LIBS = -ltermcap -lcurses -lreadline -lhistory
# Bibliothèques supplémentaires spécifiques à SunOS/Solaris
LIBS_SunOS = -lnsl -lsocket
# Bibliothèques supplémentaires spécifiques à Linux
LIBS_Linux = -lnsl
# Bibliothèques supplémentaires spécifiques à MacOSX
LIBS_Darwin = 
# Ajout des bibliothèques spécifiques
LIBS += $(LIBS_$(SYSTEM))

all: $(PROGS)

# Règle générique pour compiler un fichier source .c en un fichier
# objet .o
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

client.bin : $(SOURCES_client:%.c=%.o)
	$(CC) $(LDFLAGS) $(SOURCES_client:%.c=%.o) -o $@ $(LIBS)

serveur.bin : $(SOURCES_serveur:%.c=%.o)
	$(CC) $(LDFLAGS) $(SOURCES_serveur:%.c=%.o) -o $@ $(LIBS)

gestiondonnees.bin : $(SOURCES_GestionDonnees:%.c=%.o)
	$(CC) $(LDFLAGS) $(SOURCES_GestionDonnees:%.c=%.o) -o $@ $(LIBS)
	
clean : 
	rm -f ${PROGS} *.o depends.mk

distclean : clean
	rm -f depends.mk

# Gestion automatique des dépendances : on laisse gcc les calculer et
# on inclut juste le fichier produit
depends.mk: Makefile
	$(CC) -MM $(SOURCES) | sed -e 's/^\(.*:\)/$@ \1/' > $@

include depends.mk

