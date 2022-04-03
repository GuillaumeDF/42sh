/*
** my_execute.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh/sources
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Fri Oct  9 12:05:12 2015 Clément Weber
** Last update Fri Oct 23 12:47:34 2015 Guillaume Djaider Fornari
*/

#include <stdio.h>
#include "my_42sh.h"
#include "error.h"

int		my_execute(t_env *shell)
{
  t_shell	value;
  int		i;

  i = 0;
  if (shell->path[i] == NULL)
    return (-1);
  while (shell->path[i])
    {
      if (access(shell->new_path[i], F_OK) == 0)
	{
	  value.pid =fork();
	  if (value.pid == 0)
	    execve(shell->new_path[i], shell->expr, shell->envN);
	  else
	    wait(&value.pid);
	  return (0);
	}
      i++;
    }
  my_putstr(shell->expr[0]);
  my_puterr(CMD_FAIL_E);
  return (-1);
}
