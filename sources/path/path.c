/*
** path.c for  in /home/djaide_g/rendu/PSU_2014_minishell2/recode/test
** 
** Made by Guillaume Djaider Fornari
** Login   <djaide_g@epitech.net>
** 
** Started on  Wed Jul 15 19:02:40 2015 Guillaume Djaider Fornari
** Last update Thu Oct 22 15:13:47 2015 Guillaume Djaider Fornari
*/

#include "my_42sh.h"
#include "error.h"

static char	**my_copy_env(char **path, char *argv)
{
  t_env		shell;
  int		i;
  int		b;

  i = 0;
  if ((shell.new_path = my_xmalloc(sizeof(char *) *
				   width_tab(path) + 8)) == NULL)
    return (NULL);
  while (path[i] != '\0')
    {
      b = 0;
      if ((shell.new_path[i] = my_xmalloc(sizeof(char)
				      * (my_strlen(path[i])
					 + my_strlen(argv)) + 10)) == NULL)
	return (NULL);
      while (path[i][b] != '\0')
        {
          shell.new_path[i][b] = path[i][b];
          b++;
        }
      shell.new_path[i][b] = '\0';
      i++;
    }
  shell.new_path[i] = NULL;
  return (shell.new_path);
}

char		**my_generate_path(char **path, char *argv)
{
  t_env		shell;
  int		b;
  int		a;

  shell.i = 0;
  if (argv == NULL || path == NULL)
    return (NULL);
  shell.new_path = my_copy_env(path, argv);
  while (shell.new_path[shell.i] != NULL)
    {
      b = 0;
      while (shell.new_path[shell.i][b])
	b++;
      shell.new_path[shell.i][b++] = '/';
      a = 0;
      while (argv[a] != '\0')
	{
	  shell.new_path[shell.i][b] = argv[a++];
	  b++;
	}
      shell.new_path[shell.i][b] = '\0';
      shell.i++;
    }
  shell.new_path[shell.i] = NULL;
  return (shell.new_path);
}

char		**copy_path(char **env, int len)
{
  t_env		shell;
  int		a;
  int		b;

  a = 0;
  shell.i = 0;
  if ((shell.path = my_xmalloc(sizeof(char *) * (width_tab(env) + 1))) == NULL)
    return (NULL);
  while (env[len][shell.i] != '\0')
    {
      b = 0;
      if (env[len][shell.i] == '/' && env[len][shell.i] != '\0')
	{
	  if ((shell.path[a]
	       = my_xmalloc(sizeof(char) * (my_strlen(env[len]) + 1))) == NULL)
	    return (NULL);
	  while (env[len][shell.i] != ':' && env[len][shell.i] != '\0')
	    shell.path[a][b++] = env[len][shell.i++];
	  shell.path[a++][b] = '\0';
	}
      else
	shell.i++;
    }
  shell.path[a] = NULL;
  return (shell.path);
}

char		**my_find_path(char **env)
{
  int		i;
  char		**path;

  i = 0;
  if (env == NULL)
    return (NULL);
  while (env[i] != '\0')
    {
      if (env[i][0] == 'P' && env[i][1] == 'A'
          && env[i][2] == 'T' && env[i][3] == 'H')
        {
          path = copy_path(env, i);
          return (path);
        }
      i++;
    }
  write(STDERR_FILENO, PATH_E, my_strlen(PATH_E));
  return (NULL);
}
