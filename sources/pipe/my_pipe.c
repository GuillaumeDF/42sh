/*
** my_pipe.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Sun Oct 11 19:16:49 2015 Clément Weber
** Last update Thu Oct 22 11:42:53 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int		my_nb_pipe(char **expr, int i)
{
  int		cpt;

  cpt = 0;
  while (expr[i])
    {
      if (expr[i][0] == '|')
        cpt++;
      i++;
    }
  return (cpt);
}

char		**my_tab_pipe(int *i, t_env set)
{
  t_shell	value;
  int		a;

  a = 0;
  if ((value.tab = my_xmalloc(sizeof(char *) * width_tab(set.expr))) == NULL)
    return (NULL);
  if (set.expr == NULL)
    return (NULL);
  while ((set.expr[(*i)] != NULL) && (set.expr[(*i)][0] !=  '|')
	 && (set.expr[(*i)][0] != '>' && set.expr[(*i)][0] != '<'))
    {
      value.tab[a] = my_strdup(value.tab[a], set.expr[(*i)]);
      (*i)++;
      a++;
    }
  value.tab[a] = NULL;
  return (value.tab);
}

int		my_last_pipe(int *pipefd, char **expr, t_env set)
{
  int		a;

  a = 0;
  set.new_path = my_generate_path(set.path, expr[0]);
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    return (my_puterr(DUP2_E));
  if (set.new_path != NULL)
    {
      while (set.new_path[a])
	{
	  if (access(set.new_path[a], F_OK) == 0)
	    execve(set.new_path[a], expr, set.envN);
	  a++;
	}
      return (-1);
    }
  return (0);
}

int		my_multi_pipe(int *pipefd, char **expr, t_env set)
{
  t_shell	value;
  int		a;

  a = 0;
  if ((value.pid = fork()) == -1)
    return (-1);
  if (value.pid == 0)
    {
      set.new_path = my_generate_path(set.path, expr[0]);
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
        return (my_puterr(DUP2_E));
      while (set.new_path[a])
	{
	  if (access(set.new_path[a], F_OK) == 0)
	    execve(set.new_path[a], expr, set.envN);
	  a++;
	}
      return (-1);
    }
  return (0);
}

int		my_first_pipe(int *pipefd, char **expr, t_env set)
{
  t_shell	value;
  int		a;

  a = 0;
  if ((value.pid = fork()) == -1)
    return (-1);
  if (value.pid == 0)
    {
      set.new_path = my_generate_path(set.path, expr[0]);
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
        return (my_puterr(DUP2_E));
      while (set.new_path[a])
	{
	  if (access(set.new_path[a], F_OK) == 0)
	    execve(set.new_path[a], expr, set.envN);
	  a++;
	}
      return (-1);
    }
  return (0);
}
