/*
** my_cd_previous.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh/sources/builtins
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Sun Oct 11 14:31:11 2015 Clément Weber
** Last update Thu Oct 22 11:53:16 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int	my_cd_back(char **argv)
{
  (void) argv;
  if ((chdir("..")) == -1)
    {
      write(STDERR_FILENO, DIRECTION_E, my_strlen(DIRECTION_E));
      return (-1);
    }
  return (0);
}
