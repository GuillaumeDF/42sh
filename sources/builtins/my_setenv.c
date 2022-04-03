/*
** my_setenv.c for  in /home/djaide_g/rendu/PSU_2014_minishell2
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Sun Jul 26 22:27:32 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 11:43:18 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

static char	*my_create_line(char **argv)
{
  t_shell	tab;
  int		i;
  int		a;

  i = 0;
  a = 0;
  if ((tab.buffer = my_xmalloc(sizeof(char)
			       * (my_strlen(argv[1])
				  + my_strlen(argv[2]) + 2))) == NULL)
    return (NULL);
  while (argv[1][i])
    {
      tab.buffer[i] = argv[1][i];
      i++;
    }
  tab.buffer[i] = '=';
  i++;
  while (argv[2][a])
    {
      tab.buffer[i] = argv[2][a];
      i++;
      a++;
    }
  tab.buffer[i] = '\0';
  return (tab.buffer);
}

char		**my_setenv(char **env, char **argv, int *bool)
{
  t_env		shell;
  char		*new_line;

  shell.i = 0;
  if (argv == NULL || width_tab(argv) != 3)
    return (my_error_env(bool, env));
  if ((new_line = my_create_line(argv)) == NULL)
    return (my_error_env(bool, env));
  if ((shell.envN = my_xmalloc(sizeof(char*)* (width_tab(env) * 8))) == NULL)
    return (my_error_env(bool, env));
  while (env[shell.i] != '\0')
    {
      if ((shell.envN[shell.i] =
	   my_xmalloc(sizeof(char) * my_strlen(env[shell.i]) + 1)) == NULL)
	return (my_error_env(bool, env));
      shell.envN[shell.i] = my_strcpy(shell.envN[shell.i], env[shell.i]);
      shell.i++;
    }
  if ((shell.envN[shell.i] = my_xmalloc(sizeof(char) * (my_strlen(argv[1]) +
					my_strlen(argv[2]) + 2))) == NULL)
    return (my_error_env(bool, env));
  shell.envN[shell.i] = my_strcpy(shell.envN[shell.i], new_line);
  shell.envN[shell.i + 1] = NULL;
  my_free(env);
  return (shell.envN);
}
