/*
** execute_double_redi_left.c for  in /home/djaide_g/rendu/PSU_2014_42sh/sources/redirection
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Thu Oct 22 14:43:09 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 14:43:11 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

int	execute_double_redi_left(char **str_left, char **generate, t_env set)
{
  int	n;

  n = 0;
  while (str_left[n] != '\0')
    {
      my_son_redirection(generate, str_left[n], set);
      if (my_delete_temp(set.envN) == -1)
	return (-1);
      write(STDIN_FILENO, "\n", 1);
      n = n + 1;
    }
  return (0);
}
