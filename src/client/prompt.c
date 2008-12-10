#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <reseau/protocole.h>
#include <common.h>
#include "client.h"

extern prot_params_t prot_params;

char prompt[PROMPT_SIZE];

char *
lire_ligne (char *prompt)
{
  char *line;
  line = readline (prompt);
  add_history (line);
  return (line);
}

void
fancy_prompt ()
{
  snprintf (prompt, PROMPT_SIZE - 1, "%s:%s(%s)> ", prot_params.host,
	    prot_params.port, (prot_params.type == sock_tcp) ? "tcp" : "udp");
}

char *
lire_commande ()
{
  return lire_ligne (prompt);
}

char *
extraire_parametre (char *c)
{
  char *p = c;
  while (*p != '\0')
    {
      if (*p == ' ')
	{
	  *p = '\0';
	  ++p;
	  return p;
	}
      ++p;
    }
  return p;
}
