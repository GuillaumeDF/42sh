/*
** my_parser_pipe_redi.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Sun Oct 11 19:11:16 2015 Clément Weber
** Last update Thu Oct 22 01:37:19 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int		my_parser_last_pipe_redi(int *i, int *pipefd, t_env set)
{
  t_shell	value;

  if ((value.tab = my_tab_pipe(i, set)) == NULL)
    return (-1);
  if (set.expr[*i] == NULL)
    my_last_pipe(pipefd, value.tab, set);
  else
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	return (my_puterr(DUP2_E));
      if (my_redirection_right(i, value.tab, set) == -1)
	return (-1);
    }
  my_free(value.tab);
  return (0);
}

int		my_parser_multi_pipe_redi(int *i,  int *pipefd, t_env set)
{
  t_shell	value;

  while (my_nb_pipe(set.expr, (*i)++) > 1)
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	return (my_puterr(DUP2_E));
      if (pipe(pipefd) == -1)
        return (my_puterr(PIPE_E));
      if ((value.tab = my_tab_pipe(i, set)) == NULL)
	return (-1);
      ((set.expr[*i][0] == '>') ||  (set.expr[*i][0] == '<'))
	? my_redirection_right(i, value.tab, set) :
	my_multi_pipe(pipefd, value.tab, set);
      my_free(value.tab);
    }
  return (0);
}

int		my_parser_first_pipe_redi(int *i, int *pipefd, t_env set)
{
  t_shell	value;

  if (pipe(pipefd) == -1)
    return (my_puterr(PIPE_E));
  if ((value.tab = my_tab_pipe(i, set)) == NULL)
    return (-1);
  ((set.expr[*i][0] == '>' || (set.expr[*i][0] == '<'))
   ? my_redirection_right(i, value.tab, set) :
   my_first_pipe(pipefd, value.tab, set));
  my_free(value.tab);
  return (0);
}

int		my_parser_pipe_redi(int *pipefd, t_env set)
{
  int		i;

  i = 0;
  if (my_parser_first_pipe_redi(&i, pipefd, set) == -1)
    return (-1);
  if (my_parser_multi_pipe_redi(&i, pipefd, set) == -1)
    return (-1);
  if (my_parser_last_pipe_redi(&i, pipefd, set) == -1)
    return (-1);
  return (0);
}
