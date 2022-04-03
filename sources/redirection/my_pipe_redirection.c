/*
** my_pipe_redirection.c for  in /home/djaide_g/rendu/42SH_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Sun Oct  4 15:49:13 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 16:57:29 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int		my_redirection(int i, t_env set, char **tab)
{
  int		a;

  a = 0;
  if (my_strcmp("<<", set.expr[i]) == 0)
    {
      while (set.new_path[a])
	{
	  if (my_check_double_left(set, tab) == 0)
	    return (0);
	  a++;
	}
      return (0);
    }
  return (-1);
}

int		my_redirection_open(t_env set, int n)
{
  t_shell	value;

  if ((my_strcmp("<", set.expr[n]) == 0))
    return (open(set.expr[n + 1], O_APPEND
		 | O_RDWR , S_IRUSR | S_IWUSR));
  else
    value.fd = ((my_strcmp(">>", set.expr[n]) == 0) ?
     open(set.expr[n + 1], O_CREAT | O_APPEND | O_WRONLY , S_IRUSR | S_IWUSR) :
     open(set.expr[n + 1], O_CREAT | O_WRONLY , S_IRUSR | S_IWUSR));
  return (value.fd);
}

int		my_redirection_right(int *i, char **tab, t_env set)
{
  t_shell	value;

  set.new_path = my_generate_path(set.path, tab[0]);
  if (my_redirection(*i, set, tab) == 0)
    return (-1);
  if ((value.fd = my_redirection_open(set, *i)) == -1)
    return (my_puterr(OPEN_E));
  value.i = ((my_strcmp("<", set.expr[*i]) == 0) ?
       dup2(value.fd, 0) : dup2(value.fd, 1));
  if (value.i == -1)
    return (my_puterr(DUP2_E));
  value.i = 0;
  while (set.new_path[value.i])
    {
      if (access(set.new_path[value.i], F_OK) == 0)
	execve(set.new_path[value.i], tab, set.envN);
      value.i++;
    }
  return (-1);
}

int		my_pipe_redi(t_env shell)
{
  int		pipefd[2];
  t_shell	value;

  if ((value.pid = fork()) == -1)
    return (-1);
  if (value.pid == 0)
    {
      my_parser_pipe_redi(pipefd, shell);
      return (-1);
    }
  else
    wait(&value.pid);
  return (0);
}
