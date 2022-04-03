/*
** get_next_line.c for get_next_line in /home/messin_b
** 
** Made by Andrea Messines
** Login   <messin_b@epitech.net>
** 
** Started on  Sat Apr 18 15:43:10 2015 Andrea Messines
** Last update Tue Oct 20 20:01:34 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

static char		*get_next_line_termcaps(const int fd, int *n)
{
  struct termios	t;
  struct termios	old;
  char			buffer[6];
  char			*str;
  int			i;

  i = 0;
  if ((str = my_xmalloc((sizeof(char) * 7))) == NULL || fd == -1 ||
      set_get_next(&t, &old) == -1)
    return (NULL);
  str[0] = '\0';
  buffer[0] = 0;
  buffer[2] = 0;
  read(fd, buffer, 6);
  while (buffer[0] != 10 && buffer[0] != 12 && buffer[0] != 9)
    {
      if (check_get_next(&t, &old, buffer) == -1)
	return (my_get_write());
      modif_get_next(buffer, &str, &i);
      buffer[2] = 0;
      read(fd, buffer, 6);
    }
  set_buffer(buffer, &str, &n, i);
  my_putchar('\n');
  return (unset_get_next(&t, &old, str, buffer));
}

static int		check_env_get_next(char **env)
{
  int			n;

  n = 0;
  while (env[n] != '\0' && env[n] != NULL
    && my_strcmp( "TERM=xterm", env[n]) != 0)
    n = n + 1;
  if (env[n] != NULL && env[n] != '\0')
    if (my_strcmp( "TERM=xterm", env[n]) == 0)
      return (0);
  return (-1);
}

char			*my_realloc(char *str)
{
  int			i;
  int			len;
  char			*str2;

  i = 0;
  if (str[0] != 0)
    len = my_strlen(str);
  else
    len = 1;
  if ((str2 = my_xmalloc((len + 2) * sizeof (char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i++;
    }
  str2[i] = '\0';
  free(str);
  return (str2);
}

char			*get_next_line_basic(const int fd)
{
  int			i;
  char			buffer[1];
  char			*str;
  int			ret;
  int			n;

  n = 0;
  i = 0;
  if ((str = my_xmalloc(2 * sizeof(char))) == NULL)
    return (NULL);
  str[0] = 0;
  while ((ret = read(fd, buffer, 1)) > 0 && buffer[0] != '\n' && n++ < 20)
    {
      if ((str = my_realloc(str)) == NULL)
	return (NULL);
      str[i] = buffer[0];
      str[i + 1] = '\0';
      if (buffer[0] == ' ')
	n = 0;
      i++;
    }
  if ((i == 0 && ret == 0)|| (buffer == NULL) || (n > 20))
    return (NULL);
  return (str);
}

char			*get_next_line(const int fd, char **env)
{
  char			*str;
  int			n;

  n = 0;
  if (env == NULL || env == '\0' || check_env_get_next(env) == -1)
    str = get_next_line_basic(fd);
  else
    str = get_next_line_termcaps(fd, &n);
  if (n == 1)
    {
      str = my_create_autocomplete(str);
      if (my_autocomplete(str) == -1)
	return (NULL);
      return (str);
    }
  return (str);
}
