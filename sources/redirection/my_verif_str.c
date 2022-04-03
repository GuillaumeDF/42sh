/*
** my_verif_str.c for verif_str in /home/messin_b/PSU/PSU_2014_42sh/sources
** 
** Made by Andrea Messines
** Login   <messin_b@epitech.net>
** 
** Started on  Fri Oct  9 16:49:55 2015 Andrea Messines
** Last update Tue Oct 20 14:03:42 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

static char	***verif_str_specific(char ***str, int n)
{
  char		*argv[2];
  int		q;
  int		i;
  int		x;

  q = 0;
  i = 2;
  x = 1;
  argv[0] = str[n][0];
  argv[1] = str[n][1];
  while (str[n][++x] != NULL)
    if (my_strcmp_comp(str[n][x], "<") == 0 ||
	my_strcmp_comp(str[n][x], ">") == 0)
      return (str);
  while (str[n][i] != NULL)
    {
      str[n][q] = str[n][i];
      q = q + 1;
      i = i + 1;
    }
  str[n][q] = argv[0];
  str[n][q + 1] = argv[1];
  return (str);
}

char		***verif_str(char ***str)
{
  int		n;

  n = 0;
  while (str[n] != NULL)
    {
      if (str[n][0][0] == '<' || str[n][0][0] == '>')
	{
	  if (str[n][1] != NULL)
	    str = verif_str_specific(str, n);
	}
      n = n + 1;
    }
  return (str);
}
