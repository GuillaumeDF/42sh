/*
** my_getenv.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 16:30:33 2015 Clément Weber
** Last update Tue Oct 20 18:11:40 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

static int	my_find_getenv(char *argc, char **env)
{
  int		i;
  int		b;
  int		cpt;

  cpt = 0;
  i = 0;
  while (env[i] != '\0')
    {
      b = 0;
      while (argc[b] != '\0')
        {
          if (argc[b] == env[i][b])
            cpt++;
          else
            cpt = 0;
          if (argc[cpt] == '\0')
            return (i);
          b++;
        }
      i++;
    }
  return (-1);
}

static char	*show_env(char **env, int len)
{
  int		i;
  int		a;
  int		mal;
  t_shell	tab;

  i = 0;
  a = 0;
  mal = 0;
  while (env[len][mal] != '\0')
    mal++;
  if ((tab.buffer = my_xmalloc(sizeof(char) * mal)) == NULL)
    return (NULL);
  while ((env[len][i] != '=') && (env[len][i] != '\0'))
    i++;
  i++;
  while (env[len][i])
    {
      tab.buffer[a] = env[len][i];
      a++;
      i++;
    }
  tab.buffer[a] = '\0';
  return (tab.buffer);
}

char		*my_getenv(char *argc, char **env)
{
  int		len;

  if (argc == NULL)
    return (NULL);
  if ((len = my_find_getenv(argc, env)) == -1)
    {
      write(STDERR_FILENO, ENV_E, 52);
      return (NULL);
    }
  return (show_env(env, len));
}
