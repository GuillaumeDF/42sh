/*
** my_separator.c for  in /home/djaide_g/rendu/42SH_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Mon Oct  5 20:37:15 2015 Guillaume Djaider Fornari
** Last update Sun Oct 11 19:54:54 2015 Clément Weber
*/

#include "my_42sh.h"

static int	next_cmd(char ***expr, int *i)
{
  (*i)++;
  while ((expr[*i][0][0] != ';') && (my_strcmp(expr[*i][0] , "||") == 0)
         && (my_strcmp(expr[*i][0] , "&&") == 0) && (expr[*i] != NULL))
    (*i)++;
  (*i)++;
  return (0);
}

int		my_find_separator(int bool, char ***expr, int *i)
{
  (*i)++;
  if (expr[*i] == NULL)
    return (-1);
  if (((my_strcmp(expr[*i][0], "&&") == 0)) && (expr[*i + 1] != NULL))
    (bool == 0) ? (*i)++ : next_cmd(expr , i);
  else if ((expr[*i + 1] != NULL) && (my_strcmp(expr[*i][0], "||") == 0))
    (bool == 0) ? next_cmd(expr , i) : (*i)++;
  else if ((expr[*i][0][0] == ';') && (expr[*i + 1] != NULL))
    (*i)++;
  return (0);
}
