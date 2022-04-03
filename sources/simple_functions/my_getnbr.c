/*
** my_getnbr.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/sources/simple_functions
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Thu Oct 22 17:21:50 2015 max eizenberg
** Last update Thu Oct 22 17:34:02 2015 max eizenberg
*/

#include "my_42sh.h"

static int	verif_getnbr(const char *str)
{
  int		a;
  int		ver;

  a = 0;
  ver = 0;
  while (str[a] != '\0')
    {
      if (str[a] != '\0')
	ver++;
      a++;
    }
  return (ver % 2 == 0 ? 0 : 1);
}

static int	check_number(const char *str)
{
  int		a;
  int		cpt;

  a = 0;
  cpt = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= '0' && str[a] <= '9')
	cpt++;
      a++;
    }
  return (cpt);
}

int		my_getnbr(const char *str)
{
  int		a;
  int		b;
  int		i;

  i = 1;
  a = 0;
  b = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= '0' && str[a] <= '9')
	{
	  if (i < check_number(str))
	    {
	      b = (b + (str[a] - 48)) * 10;
	      i++;
	    }
	  else
	    b = b + (str[a] - 48);
	}
      a++;
    }
  if (b > INT_MAX || b < INT_MIN)
    return (0);
  return (verif_getnbr(str) == 1 ? b * -1 : b);
}
