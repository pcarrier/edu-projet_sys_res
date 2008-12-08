
PROGS=client serveur

SOURCES_client=client_UDP_iteratif.c fon.c
SOURCES_serveur=serveur_UDP_iteratif.c fon.c

SOURCES=$(SOURCES_client) $(SOURCES_serveur)

# On stocke dans SYSTEM le r√©sultat de la commande 'uname -s'
# Il faut les deux lignes dans cet ordre pour que √ßa marche aussi bien avec le make de Solaris que celui de Linux
SYSTEM = $(shell uname -s)
SYSTEM:sh = uname -s

# Options de compilation (‡ commenter ou pas suivant ce qu'on veut)
# On garde les informations de dÈbogage
CFLAGS += -g
# Optimisation du code par le compilateur
CFLAGS += -O2
# DÈtection d'un maximum d'erreurs
CFLAGS += -Wall
# On ne crÈe pas le programme tant qu'il y a des erreurs
CFLAGS += -Werror

# Si la ligne suivante est dÈcommentÈe, du code de debug est compilÈ
# dans fon.c. Il permet d'observer les messages.
CPPFLAGS += -DDEBUG

# Compilateur ‡ utiliser
CC=gcc

# BibliothËques ‡ utiliser
LIBS = -ltermcap -lcurses 
# BibliothËques supplÈmentaires spÈcifiques ‡ SunOS/Solaris
LIBS_SunOS = -lnsl -lsocket
# BibliothËques supplÈmentaires spÈcifiques ‡ Linux
LIBS_Linux = -lnsl
# BibliothËques supplÈmentaires spÈcifiques ‡ MacOSX
LIBS_Darwin = 
# Ajout des bibliothËques spÈcifiques
LIBS += $(LIBS_$(SYSTEM))

all: $(PROGS)

# RËgle gÈnÈrique pour compiler un fichier source .c en un fichier
# objet .o
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

client : $(SOURCES_client:%.c=%.o)
	$(CC) $(LDFLAGS) $(SOURCES_client:%.c=%.o) -o $@ $(LIBS)

serveur : $(SOURCES_serveur:%.c=%.o)
	$(CC) $(LDFLAGS) $(SOURCES_serveur:%.c=%.o) -o $@ $(LIBS)

clean : 
	rm -f ${PROGS} *.o depends.mk

# Gestion automatique des dÈpendances : on laisse gcc les calculer et
# on inclut juste le fichier produit
depends.mk: Makefile
	gcc -MM $(SOURCES) | sed -e 's/^/$@ /' > $@

include depends.mk



