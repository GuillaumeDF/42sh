/*
** my_autocomplete.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/djaide_g
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Fri Oct  2 16:31:39 2015 max eizenberg
** Last update Mon Oct 19 22:12:53 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int		my_autocomplete(char *param)
{
  struct dirent	*value;
  DIR		*rep;

  if ((rep = opendir(".")) == NULL)
    return (my_puterr(OPENDIR_E));
  my_putchar('\n');
  while ((value = readdir(rep)))
    {
      if (my_strcmp_comp(param, value->d_name) == 0)
	{
	  my_putstr(value->d_name);
	  my_putchar('\n');
	}
    }
  my_putchar('\n');
  return (0);
}

char		*my_create_autocomplete(char *str)
{
  int		n;
  int		i;
  char		*end;

  n = 0;
  i = 0;
  if (str == NULL)
    return ("\0");
  while (str[n] != '\0')
    n++;
  while (str[n] != ' ' && n != 0)
    n = n - 1;
  if (n == 0)
    return (str);
  n = n + 1;
  if ((end = my_xmalloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[n] != '\0')
    {
      end[i] = str[n];
      i++;
      n++;
    }
  end[i] = '\0';
  return (end);
}
