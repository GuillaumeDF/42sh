/*
** my_builtins_env.c for  in /home/djaide_g/rendu/42SH_RELOAD
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Sat Oct  3 00:39:48 2015 Guillaume Djaider Fornari
** Last update Wed Oct 21 19:14:17 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

char	**my_show_env(char **envN, char **argc, int *bool)
{
  int	i;

  i = 0;
  (void) argc;
  if (envN == NULL)
    {
      *bool = -1;
      return (envN);
    }
  while (envN[i])
    {
      printf("%s\n", envN[i]);
      i++;
    }
  return (envN);
}
