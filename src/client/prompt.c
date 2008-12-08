#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char *
getline ()
{
  char *line;
  line = readline ("> ");
  add_history (line);
  return (line);
}
