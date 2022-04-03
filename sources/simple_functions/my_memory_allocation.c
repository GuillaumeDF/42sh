/*
** my_memory_allocation.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 15:45:29 2015 Clément Weber
** Last update Tue Oct 20 20:02:55 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

void	*my_xmalloc(int i)
{
  void	*verif;

  if ((verif = malloc(i)) == NULL)
    {
      my_puterr(MALLOC_E);
      return (NULL);
    }
  return (verif);
}
