/*
** my_unsetenv.c for  in /home/djaide_g/rendu/42SH_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Sat Oct  3 01:39:59 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 11:41:52 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

static int	verification(char *line_env, char *argv)
{
  int		i;
  char		*compare;

  i = 0;
  if ((compare = my_xmalloc(sizeof(char) * (my_strlen(line_env) + 1))) == NULL)
    return (-1);
  while (line_env[i] != '=')
    {
      compare[i] = line_env[i];
      i++;
    }
  compare[i] = '\0';
  if (my_strcmp(compare, argv) == 0)
    {
      free(compare);
      return (1);
    }
  free(compare);
  return (0);
}

char		**my_unsetenv(char **env, char **argv, int *bool)
{
  t_env		shell;
  int		i;
  int		n;

  n = 0;
  i = 0;
  if (argv == NULL || argv[1] == NULL)
    return (my_error_env(bool, env));
  if ((shell.envN = my_xmalloc(sizeof(char *) * (width_tab(env)))) == NULL)
    return (my_error_env(bool, env));
  while (env[i] != '\0')
    {
      if (verification(env[i], argv[1]) != 1)
	{
	  shell.envN[n] = my_strdup(shell.envN[i], env[i]);
	  n++;
	}
      i++;
    }
  shell.envN[i - 1] = NULL;
  my_free(env);
  return (shell.envN);
}
