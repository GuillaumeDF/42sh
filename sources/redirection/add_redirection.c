/*
** add_redirection.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/djaide_g
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Fri Oct  2 16:29:43 2015 max eizenberg
** Last update Tue Oct 20 17:59:29 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

char		**add_redirection(char **end, char *buffer)
{
  t_shell	value;
  int		n;

  n = 0;
  if (end == '\0')
    n = 2;
  else
    while (end[n] != '\0')
      n = n + 1;
  if ((value.tab = my_xmalloc(sizeof(char *) * (n + 2))) == NULL)
    return (NULL);
  n = 0;
  if (end != NULL)
    while (end[n] != '\0')
      {
	value.tab[n] = end[n];
	n = n + 1;
      }
  value.tab[n] = buffer;
  value.tab[n + 1] = '\0';
  return (value.tab);
}
