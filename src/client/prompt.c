#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char *
getline (char *prompt)
{
  char *line;
  line = readline (prompt);
  add_history (line);
  return (line);
}

char *
getcommande () {

}
