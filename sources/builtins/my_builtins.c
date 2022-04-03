/*
** my_builtins.c for  in /home/djaide_g/rendu/Brouillon/Minishell/42SH_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Thu Oct  1 17:02:37 2015 Guillaume Djaider Fornari
** Last update Wed Oct 21 20:57:28 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

char		**my_functions_env()
{
  char		**functions;

  if ((functions = my_xmalloc(sizeof(char *) * 5)) == NULL)
    return (NULL);
  functions[0] = my_strdup(functions[0], "setenv");
  functions[1] = my_strdup(functions[1], "env");
  functions[2] = my_strdup(functions[2], "unsetenv");
  functions[3] = my_strdup(functions[3], "cd");
  functions[4] = NULL;
  return (functions);
}

char		**my_functions_simple()
{
  char		**functions;

  if ((functions = my_xmalloc(sizeof(char *) * 4)) == NULL)
    return (NULL);
  functions[0] = my_strdup(functions[0], "echo");
  functions[1] = my_strdup(functions[3], "..");
  functions[2] = NULL;
  return (functions);
}

static int	my_find_functions(char **functions, char **argv)
{
  int		i;

  i = 0;
  while (functions[i])
    {
      if (my_strcmp(argv[0], functions[i]) == 0)
        return (i);
      i++;
    }
  return (-1);
}

int		my_builtins(t_env *shell)
{
  t_shell	value;
  char		**(*cmd_env[4])(char **, char **, int *);
  int		(*cmd_simple[2])(char **);

  value.bool = 0;
  if ((value.i = my_find_functions(shell->func_env, shell->expr)) != -1)
    {
      cmd_env[0] = my_setenv;
      cmd_env[1] = my_show_env;
      cmd_env[2] = my_unsetenv;
      cmd_env[3] = my_cd;
      shell->envN = cmd_env[value.i](shell->envN, shell->expr, &value.bool);
      if ((value.i == 2 || value.i == 0)
	  && ((my_strcmp("PATH", shell->expr[1]) == 0)))
	shell->path = my_find_path(shell->envN);
      return (value.bool);
    }
  if ((value.i = my_find_functions(shell->func_simple, shell->expr)) != -1)
    {
      cmd_simple[0] = my_echo;
      cmd_simple[1] = my_cd_back;
      return (cmd_simple[value.i](shell->expr));
    }
  return (1);
}
