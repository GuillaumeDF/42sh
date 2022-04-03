/*
** my_son_redirection.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/djaide_g
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Fri Oct  2 16:22:30 2015 max eizenberg
** Last update Tue Oct 20 17:57:51 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

int		my_son_open(char *str)
{
  t_shell	value;;

  if ((value.fd = open(".temp", O_CREAT |
		       O_RDWR, S_IRUSR | S_IWUSR)) == -1)
    return (my_puterr(OPEN_E));
  write(value.fd, str, my_strlen(str));
  close(value.fd);
  if ((value.fd = open(".temp", O_CREAT | O_RDWR
		       | O_APPEND, S_IRUSR | S_IWUSR)) == -1)
    return (my_puterr(OPEN_E));
  if (dup2(value.fd, STDIN_FILENO) == -1)
    return (my_puterr(DUP2_E));
  return (0);
}

int		my_son_redirection(char **a, char *str, t_env set)
{
  int		i;
  t_shell	value;

  i = 0;
  if (set.new_path == NULL || set.new_path == '\0')
    return (-1);
  if ((value.pid = fork()) == -1)
    return (-1);
  if (value.pid == 0)
    {
      my_son_open(str);
      if (set.new_path != NULL)
	while (set.new_path[i])
	  if (execve(set.new_path[i], a, set.envN) == -1)
	    i++;
      return (-1);
    }
  else
    wait(&value.pid);
  return (0);
}
