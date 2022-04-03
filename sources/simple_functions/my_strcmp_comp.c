/*
** my_strcmp_comp.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/djaide_g
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Fri Oct  2 16:31:22 2015 max eizenberg
** Last update Sun Oct 11 19:55:37 2015 Clément Weber
*/

#include "my_42sh.h"

int	my_strcmp_comp(char *str, char *argv)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      if (str[n] != argv[n])
	return (1);
      n = n + 1;
    }
  return (0);
}
