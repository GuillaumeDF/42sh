/*
** my_launcher.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Sun Oct 11 19:33:47 2015 Clément Weber
** Last update Thu Oct 22 16:54:57 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int		detect_pipe(char **expr)
{
  int		cpt;
  int		i;

  cpt = 0;
  i = 0;
  while (expr[i])
    {
      if (((expr[i][0] == '|') && (expr[i][1] == '\0')
	   && (expr[i + 1] != NULL))
          || ((expr[i][0] == '>') && expr[i + 1] != NULL)
          || ((expr[i][0] == '<') && (expr[i + 1] != NULL)))
        cpt++;
      i++;
    }
  return (cpt);
}

char		*replace_exec(char *str)
{
  int		n;
  int		i;
  char		*end;

  i = 0;
  n = 2;
  if ((end = my_xmalloc(sizeof(char) * my_strlen(str))) == NULL)
    return (str);
  while (str[n] != '\0')
    {
      end[i] = str[n];
      i++;
      n++;
    }
  end[i] = '\0';
  return (end);
}

static int	execute_cmd(t_env *shell)
{
  int		bool;

  if (detect_pipe(shell->expr) > 0)
    {
      if ((bool = my_pipe_redi(*shell)) == -1)
	return (bool);
    }
  else
    {
      if (shell->path == NULL)
	return (-1);
      shell->new_path = my_generate_path(shell->path, shell->expr[0]);
      bool = my_execute(shell);
      my_free(shell->new_path);
      return (bool);
    }
  return (0);
}

int		my_launcher(t_env *shell, char ***expr)
{
  t_shell	value;
  char		**oldpath;

  value.i = 0;
  while (expr[value.i] != NULL)
    {
      shell->expr = expr[value.i];
      if (my_strcmp_comp("./", shell->expr[0]) == 0)
        {
          shell->expr[0] = replace_exec(shell->expr[0]);
	  oldpath = shell->path;
          shell->path = creat_path(shell->expr[0]);
          shell->new_path = creat_path(shell->expr[0]);
	  my_execute(shell);
	  shell->path = oldpath;
	}
      else if ((value.bool = my_builtins(shell)) == 1)
	value.bool = execute_cmd(shell);
      my_find_separator(value.bool, expr, &value.i);
    }
  return (0);
}
