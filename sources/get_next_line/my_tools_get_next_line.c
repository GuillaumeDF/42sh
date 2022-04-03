/*
** my_tools_get_next_line.c for my_tools in /home/messin_b/PSU/PSU_2014_42sh/djaide_g
** 
** Made by Andrea Messines
** Login   <messin_b@epitech.net>
** 
** Started on  Sat Oct  3 10:53:58 2015 Andrea Messines
** Last update Sun Oct 11 23:28:02 2015 Andrea Messines
*/

#include "my_42sh.h"
#include "error.h"

int	set_get_next(struct termios *t, struct termios *old)
{
  if (tcgetattr(0, t) == -1)
    return (-1);
  if (tgetent(0, "xterm") != 1)
    return (-1);
  *old = *t;
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  t->c_lflag &= ~ECHO;
   if (tcsetattr(1, 0, t) == -1)
     return (-1);
   return (0);
}

char	*unset_get_next(struct termios *t, struct termios *old,
			char *str, char *buffer)
{
  if (buffer[0] == 9)
    {
      t = old;
      if (tcsetattr(1, 0, t) == -1)
	return (NULL);
      return (str);
    }
  if (buffer[0] == 12)
    {
      t = old;
      if (tcsetattr(1, 0, t) == -1)
	return (NULL);
      return ("clear");
    }
  t = old;
  if (tcsetattr(1, 0, t) == -1)
    return (NULL);
  return (str);
}

int	check_get_next(struct termios *t, struct termios *old, char *buffer)
{
  if (buffer[0] == 4)
    {
      t = old;
      if (tcsetattr(1, 0, t) == -1)
	return (-1);
      return (-1);
    }
  return (0);
}

int	modif_get_next(char *buffer, char **arg, int *i)
{
  char	*str;

  str = *arg;
  if (((buffer[2] <= 68) && (buffer[2] >= 65)) ||
      buffer[0] <= 6 || ((buffer[0] > 13) && (buffer[0] < 32)))
  return (-1);
  else if (buffer[0] != 127)
    {
      my_putchar(buffer[0]);
      if ((str = my_realloc(str)) == NULL)
	return (my_puterr(MALLOC_E));
      str[*i] = buffer[0];
      str[*i + 1] = '\0';
      *i = *i + 1;
   }
  else if (*i >= 1)
    {
      my_putchar('\b');
      my_putchar(' ');
      my_putchar('\b');
      *i = *i - 1;
    }
  *arg = str;
  return (0);
}

int	set_buffer(char *buffer, char **arg, int **j, int i)
{
  char	*str;
  int	n;

  n = 0;
  str = *arg;
  if (buffer[0] == 9)
    {
      n = 1;
      str[i] = '\0';
    }
  else
    str[i] = '\0';
  *arg = str;
  **j = n;
  return (0);
}
