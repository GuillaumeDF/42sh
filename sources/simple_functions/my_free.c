/*
** my_free.c for  in /home/djaide_g/rendu/PSU_2014_42sh/42sh_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Tue Oct  6 00:16:10 2015 Guillaume Djaider Fornari
** Last update Sun Oct 11 19:53:13 2015 Clément Weber
*/

#include "my_42sh.h"

char	**my_free(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL || (my_strcmp(tab[0], "clear") != 0))
    return (NULL);
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (tab);
}

char	***my_free_expr(char ***tab)
{
  int	i;
  int	a;

  i = 0;
  if (tab == NULL)
    return (NULL);
  while (tab[i])
    {
      a = 0;
      while (tab[i][a])
	{
	  free(tab[i][a]);
	  a++;
	}
      free(tab[i]);
      i++;
    }
  free(tab);
  return (tab);
}

char	*my_free_basic(char *str)
{
  if (my_strcmp(str, "clear") != 0 && str != NULL)
    free(str);
  return (str);
}
