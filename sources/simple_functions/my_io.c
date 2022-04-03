/*
** my_io.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 15:47:12 2015 Clément Weber
** Last update Tue Oct 20 19:59:13 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_puterr(char *err)
{
  write(2, err, my_strlen(err));
  return (-1);
}
