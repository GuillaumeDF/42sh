/*
** save_double_redi_gauche.c for  in /home/djaide_g/rendu/PSU_2014_42sh/sources/redirection
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Thu Oct 22 14:46:22 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 14:46:25 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

char		**save_double_redi_gauche(char *str)
{
  char		**end;
  char		*buffer;

  end = NULL;
  write(STDIN_FILENO, "> ", 2);
  buffer = get_next_line_basic(0);
  if (my_strcmp(buffer, str) == 0)
    return (end);
  end = add_redirection(end, buffer);
  while (42)
    {
      write(STDIN_FILENO, "> ", 2);
      buffer = get_next_line_basic(0);
      if (buffer == NULL)
	return (end);
      if (my_strcmp(buffer, str) == 0)
	  return (end);
      end = add_redirection(end, buffer);
    }
  return (end);
}
