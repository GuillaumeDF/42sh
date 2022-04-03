/*
** my_echo_version.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Sun Oct 11 18:53:26 2015 Clément Weber
** Last update Tue Oct 20 19:20:35 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

int	my_long_echo(char *str)
{
  if (my_strcmp(str, "--help") == 0)
    {
      my_puterr("Options :\n-n will remove last new line\n");
      my_puterr("-e will enable special sequences\n");
      my_puterr("-E will disable special sequances (Default)\n");
    }
  else
    my_puterr("My_echo - Version 20151011 - EZ-42sh\n");
  return (0);
}
