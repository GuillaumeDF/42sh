/*
** prompt.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 15:57:34 2015 Clément Weber
** Last update Mon Oct 19 23:36:28 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

void		display_prompt()
{
  static int	cptr = 1;
  struct passwd	*user;
  uid_t		uid;

  uid = getuid();
  user = getpwuid(uid);
  my_putchar('(');
  my_putstr(user->pw_name);
  my_putchar('@');
  my_putstr("pc-");
  my_putstr(user->pw_name);
  my_putchar(' ');
  my_putnbr(cptr);
  my_putchar(')');
  cptr = cptr + 1;
}
