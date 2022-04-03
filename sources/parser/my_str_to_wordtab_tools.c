/*
** my_str_to_wordtab_tools.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh/sources
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Fri Oct  9 11:57:36 2015 Clément Weber
** Last update Tue Oct 20 03:00:33 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int	verif(char *argv, int *i, char *str)
{
  if ((argv[*i]) && (argv[*i + 1]))
    {
      if ((argv[*i] == str[0]) && (argv[*i + 1] == str[1]))
        return (1);
      if ((argv[*i] == str[0]) && (argv[*i - 1] == str[1]))
        return (1);
    }
  return (0);
}

int	my_operator(char *new, char *argv, int *i)
{
  int	c;

  c = 0;
  while ((argv[*i] == '|') || (argv[*i] == '<') || (argv[*i] == '>')
         || (verif(argv, i, ">>") == 1)
         || ((verif(argv, i, "<<") == 1) && (argv[*i] != ' ')
	     && (argv[*i] != '\t')))
    {
      new[c] = argv[*i];
      (*i)++;
      c++;
    }
  new[c] = '\0';
  return (0);
}

int	my_argument(char *new, char *argv, int *i)
{
  int	c;

  c = 0;
  while ((argv[*i] != '|') && (argv[*i] != '<') && (argv[*i] != '>')
         && (argv[*i] != '\0') && (argv[*i] != '\n') && (argv[*i] != ' ')
         && (argv[*i] != '\t') && (argv[*i] != ';')
         && (verif(argv, i, "||") != 1) && (verif(argv, i, "&&") != 1)
         && (verif(argv, i, ">>") != 1) && (verif(argv, i, "<<") != 1))
    {
      new[c] = argv[*i];
      (*i)++;
      c++;
    }
  new[c] = '\0';
  return (0);
}

int	my_parser(char **new, char *argv, int *i)
{
  int	b;

  b = 0;
  while ((argv[*i] != ';') && (argv[*i] != '\0') && (argv[*i] != '\n')
         && (verif(argv, i, "||") != 1) && (verif(argv, i, "&&") != 1))
    {
      if ((argv[*i] != ' ') && (argv[*i] != '\t'))
	{
          if ((new[b] = my_xmalloc(sizeof(char)
                                   * my_strlen(argv) + 1)) == NULL)
            return (-1);
          (argv[*i] == '|' || argv[*i] == '<' || argv[*i] == '>'
           || verif(argv, i, ">>") == 1 || verif(argv, i, "<<") == 1)
            ? my_operator(new[b], argv, i) : my_argument(new[b], argv, i);
          b++;
	}
      else
        (*i)++;
    }
  new[b] = NULL;
  return (0);
}
