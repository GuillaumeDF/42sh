/*
** my_delete_temp.c for  in /home/djaide_g/rendu/PSU_2014_42sh/sources/simple_functions
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Tue Oct 20 21:11:22 2015 Guillaume Djaider Fornari
** Last update Tue Oct 20 21:12:06 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"

int	my_delete_temp(char **ev)
{
  pid_t	pid;
  int	i;
  char	**path;
  char	*argv[3];

  i = 0;
  if ((path = my_find_path(ev)) == NULL)
    return (-1);
  path = my_generate_path(path, "rm");
  argv[0] = "rm";
  argv[1] = ".temp";
  argv[2] = NULL;
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    while (path[i] != NULL)
      {
	if (execve(path[i], argv, ev) == -1)
	  return (-1);
	i = i + 1;
      }
  else
    wait(&pid);
  return (0);
}
