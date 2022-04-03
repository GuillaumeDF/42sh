/*
** my_getnbr.c for 42sh in /home/weber_i/rendu/PSU_2014_42sh
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Sun Oct 11 18:51:34 2015 Clément Weber
** Last update Sun Oct 11 21:32:17 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

char	*my_get_write()
{
  my_putchar('\n');
  return (NULL);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar(45);
      nb = nb * - 1;
    }
  if (nb  > 0)
    {
      if (nb / 10 == 0)
        my_putchar(nb + 48);
      else
        {
          my_putnbr(nb / 10);
          my_putchar(nb % 10 + 48);
        }
    }
}
