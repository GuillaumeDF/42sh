/*
** my_echo.c for 42SH in /home/weber_i/rendu/PSU_2014_42sh/djaide_g
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Fri Oct  2 16:28:12 2015 Clément Weber
** Last update Thu Oct 22 11:42:30 2015 Guillaume Djaider Fornari
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_42sh.h"

static int	look_for_flags(char **str, char c)
{
  int		i;

  if (c == 'e')
    {
      i = 0;
      while (str[i] != NULL)
	{
	  if (my_strcmp(str[i], "-e") == 0)
	    return (-1);
	  i = i + 1;
	}
    }
  else
    {
      i = 0;
      while (str[i] != NULL)
	{
	  if (my_strcmp(str[i], "-n") == 0)
	    return (-1);
	  i = i + 1;
	}
    }
  return (0);
}

static void	display_my_char(char c, int e)
{
  if (e == 0)
    {
      my_putchar('\\');
      my_putchar(c);
    }
  else
    {
      if (c == 'a')
	my_putchar(7);
      else if (c == 'b')
	my_putchar(8);
      else if (c == 't')
	my_putchar(9);
      else if (c == 'n')
	my_putchar(10);
      else if (c == 'v')
	my_putchar(11);
      else if (c == 'f')
	my_putchar(12);
      else if (c == 'r')
	my_putchar(13);
      else if (c == '\\')
	my_putchar(92);
    }
}

static int	is_flag(char c)
{
  if (c == 'a' || c == 'b' || c == 't' || c == 'n' ||
      c == 'n' || c == 'v' || c == 'f' || c == 'r' || c == '\\')
    return (0);
  else
    return (-1);
}

static int	my_display_echo(char **str, int e, int i)
{
  int		j;

  if (str[i] == NULL)
    return (-11);
  while (str[i] != NULL)
    {
      j = 0;
      while (str[i][j] != '\0')
	if ((str[i][j] == '\\') && (is_flag(str[i][j + 1]) == 0))
	  {
	    display_my_char(str[i][j+1], e);
	    j = j + 2;
	  }
	else
	  {
	    my_putchar(str[i][j]);
	    j++;
	  }
      if (i < (width_tab(str)))
	my_putchar(' ');
      i = i + 1;
    }
  return (0);
}

int		my_echo(char **str)
{
  int		i;
  int		flags_n;
  int		flags_e;

  flags_n = look_for_flags(str, 'n');
  flags_e = look_for_flags(str, 'e');
  if (str[1] == NULL)
    {
      my_putchar('\n');
      return (-1);
    }
  if ((my_strcmp(str[1], "--help") == 0) ||
      (my_strcmp(str[1], "--version") == 0))
    return (my_long_echo(str[1]));
  i = 1;
  while ((str[i] != NULL) && ((my_strcmp(str[i], "-n") == 0) ||
			      (my_strcmp(str[i], "-e") == 0) ||
			      (my_strcmp(str[i], "-E") == 0)))
    i = i + 1;
  my_display_echo(str, flags_e, i);
  if (flags_n == 0)
    my_putchar('\n');
  return (0);
}
