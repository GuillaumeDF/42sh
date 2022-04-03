/*
** my_strlen.c for  in /home/djaide_g/rendu/42SH_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Fri Oct  2 16:31:00 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 11:40:32 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

int	cptr_sep(char *argv)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 2;
  while (argv[i])
    {
      if (argv[i] == ';'
          || (verif(argv, &i, "||") == 1)
          || (verif(argv, &i, "&&") == 1)
          || argv[i] == '\0' || argv[i] == '\n'
	  || argv[i] == ' ')
        cpt++;
      i++;
    }
  return (cpt * 2);
}

int	cptr_ope(char *argv)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 2;
  while (argv[i])
    {
      if (argv[i] == '|'
          || (verif(argv, &i, ">>") == 1)
          || (verif(argv, &i, "<<") == 1)
          || argv[i] == '<' || argv[i] == '>' || argv[i] == ' ')
        cpt++;
      i++;
    }
  return (cpt * 2);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	width_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
