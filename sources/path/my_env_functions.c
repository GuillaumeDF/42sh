/*
** my_env_functions.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 15:41:26 2015 Clément Weber
** Last update Thu Oct 22 11:40:51 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

char		**my_env_duplicate(char **original)
{
  char		**new_env;
  int		i;

  i = 0;
  if (original == NULL)
    return (NULL);
  if ((new_env = my_xmalloc(sizeof(char *) * width_tab(original) + 8)) == NULL)
    return (NULL);
  while (original[i] != '\0')
    {
      if ((new_env[i] = my_xmalloc(sizeof(char)
				   * my_strlen(original[i]) + 1)) == NULL)
	return (NULL);
      new_env[i] = my_strcpy(new_env[i], original[i]);
      i = i + 1;
    }
  new_env[i] = NULL;
  return (new_env);
}
