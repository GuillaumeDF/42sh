/*
** signal.c for signal in /home/messin_b/PSU/PSU_2014_42sh/djaide_g
** 
** Made by Andrea Messines
** Login   <messin_b@epitech.net>
** 
** Started on  Fri Sep 25 19:35:01 2015 Andrea Messines
** Last update Thu Oct 22 15:01:57 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

void	my_signal(int sign)
{
  if (sign == 2)
    {
      printf("\n");
      display_prompt();
    }
  return ;
}

int	*my_serveur()
{
  signal(SIGINT, my_signal);
  signal(SIGKILL, my_signal);
  signal(SIGQUIT, my_signal);
  signal(SIGABRT, my_signal);
  signal(SIGCONT, my_signal);
  signal(SIGTSTP, my_signal);
  signal(SIGTTIN, my_signal);
  signal(SIGTTOU, my_signal);
  signal(SIGPIPE, my_signal);
  signal(SIGALRM, my_signal);
  return (0);
}
