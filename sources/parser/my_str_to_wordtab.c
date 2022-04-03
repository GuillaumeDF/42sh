/*
** my_tab_pipe.c for  in /home/djaide_g/rendu/PSU_2014_minishell2
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Sat Jul 25 22:46:40 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 01:35:33 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

static int	my_separator(char **new, char *argv, int *i)
{
  int		b;

  b = 0;
  if ((new[0] = my_xmalloc(sizeof(char) * 10)) == NULL)
    return (-1);
  while ((argv[*i] == ';') || (verif(argv, i, "||") == 1)
	 || (verif(argv, i, "&&") == 1))
    {
      new[0][b] = argv[*i];
      b++;
      (*i)++;
    }
  new[0][b] = '\0';
  new[1] = NULL;
  return (0);
}

char		***my_str_to_wordtab(char *argv, char ***new, int i, int a)
{
  t_shell	value;

  if (argv == NULL || argv[0] == '\0')
    return (NULL);
  if ((new = my_xmalloc(sizeof(char **) * (cptr_sep(argv) + 1))) == NULL)
    return (NULL);
  while ((argv[i] != '\0') && (argv[i] != '\n'))
    {
      if ((argv[i] != ' ') && (argv[i] != '\t'))
	{
	  if ((new[a] = my_xmalloc(sizeof(char *)
				   * (cptr_ope(argv) + 1))) == NULL)
	    return (NULL);
	  value.bool = ((argv[i] != ';') && (verif(argv, &i, "&&") != 1)
	   && (verif(argv, &i, "||") != 1))
	    ? my_parser(new[a], argv, &i) : my_separator(new[a], argv, &i);
	  if (value.bool == -1)
	    return (NULL);
	  a++;
	}
      else
	i++;
    }
  new[a] = NULL;
  return (new);
}
