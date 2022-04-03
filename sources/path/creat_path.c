/*
** creat_path.c for  in /home/eizenb_m/rendu/PSU_2014_42sh/djaide_g
** 
** Made by max eizenberg
** Login   <eizenb_m@epitech.net>
** 
** Started on  Fri Oct  2 16:28:52 2015 max eizenberg
** Last update Thu Oct 22 01:47:17 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

char	**creat_path(char *na)
{
  char	cwd[1024];
  char	**end;
  int	n;
  int	i;

  i = 0;
  n = -1;
  if ((getcwd(cwd, sizeof(cwd))) == NULL)
    return (NULL);
  if ((end = my_xmalloc(sizeof(char *) * 2)) &&
      (end[0] = my_xmalloc(sizeof(char) * (my_strlen(na)
				       + my_strlen(cwd)) + 2)) == NULL)
    return (NULL);
  while (cwd[++n] != '\0')
    end[0][n] = cwd[n];
  end[0][n] = '/';
  while (na[i] != '\0')
    {
      end[0][n + 1] = na[i];
      n = n + 1;
      i = i + 1;
    }
  end[0][n + 1] = '\0';
  return (end);
}
