/*
** simple_functions.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 15:44:20 2015 Clément Weber
** Last update Thu Oct 22 17:29:11 2015 max eizenberg
*/

#include "my_42sh.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i])
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *dest, char *src)
{
  int	i;

  i = 0;
  if ((dest = my_xmalloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*flush(char *str)
{
  int	i;

  i = 0;
  if ((my_strcmp(str, "clear")) == 0)
    return (NULL);
  while (str[i] != '\0')
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}
