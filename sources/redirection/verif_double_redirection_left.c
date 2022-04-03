/*
** verif_double_redirection_left.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/djaide_g
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Fri Oct  2 16:29:23 2015 max eizenberg
** Last update Thu Oct 22 14:45:41 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

static char	*verif_double_redirection_left(char **generate)
{
  int		n;

  n = 0;
  while (generate[n] != '\0')
    {
      if (my_strcmp(generate[n], "<<\0") == 0 && generate[n + 1] != '\0')
	return (generate[n + 1]);
      n = n + 1;
    }
  return (NULL);
}

int		my_check_double_left(t_env set, char **gen)
{
  t_shell	value;
  char		*str_redirection;

  if ((str_redirection = verif_double_redirection_left(set.expr)) != NULL)
    {
      value.tab = save_double_redi_gauche(str_redirection);
      if (value.tab == NULL)
	return (0);
      if (set.new_path != NULL)
	if (execute_double_redi_left(value.tab, gen, set) == -1)
	  return (-1);
      return (0);
    }
  return (-1);
}
