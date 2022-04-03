/*
** my_cd.c for  in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Oct  5 22:21:26 2015 Clément Weber
** Last update Thu Oct 22 01:38:52 2015 Guillaume Djaider Fornari
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_42sh.h"
#include "error.h"

static char	**my_cd_previous(char **env, char **argv)
{
  char		*old_pwd;

  (void) argv;
  old_pwd = my_getenv("OLDPWD", env);
  if (old_pwd == NULL)
    {
      my_puterr("OLDPWD Variable is not set\n");
      return (env);
    }
  if (chdir(old_pwd) == 0)
    {
      printf("%s\n", old_pwd);
      return (env);
    }
  else
    {
      my_puterr("Failed to navigate to previous location\n");
      return (env);
    }
}

static	char	**remove_old_pwd(char **env, int *bool)
{
  char		**old_pwd;

  if ((old_pwd = my_xmalloc(sizeof(char *) * 3)) == NULL)
    {
      *bool = -1;
      return (NULL);
    }
  old_pwd[0] = my_strdup(old_pwd[0], "unsetenv");
  old_pwd[1] = my_strdup(old_pwd[1], "OLDPWD");
  old_pwd[2] = NULL;
  env = my_unsetenv(env, old_pwd, bool);
  free(old_pwd);
  return (env);
}

static char	**set_old_pwd(char **env, int *bool)
{
  char		**old_pwd;
  char		buffer[1024];

  env = remove_old_pwd(env, bool);
  if ((getcwd(buffer, sizeof(buffer))) == NULL)
    {
      my_puterr(GETCWD_E);
      *bool = -1;
      return (NULL);
    }
  if ((old_pwd = my_xmalloc(sizeof(char *) * 4)) == NULL)
    {
      *bool = -1;
      return (NULL);
    }
  old_pwd[0] = my_strdup(old_pwd[0], "setenv");
  old_pwd[1] = my_strdup(old_pwd[1], "OLDPWD");
  old_pwd[2] = my_strdup(old_pwd[2], buffer);
  old_pwd[3] = NULL;
  env = my_setenv(env, old_pwd, bool);
  free(old_pwd);
  return (env);
}

char		**my_cd(char **env, char **argv, int *bool)
{
  char		*root;
  char		*dest;

  dest = NULL;
  if ((argv[1] != NULL) && (my_strcmp(argv[1], "-") == 0))
    return (my_cd_previous(env, argv));
  if ((root = my_getenv("HOME", env)) == NULL)
    {
      if ((root = my_xmalloc(sizeof(char))) == NULL)
        return (NULL);
      root[0] = '/';
    }
  if (argv[1] == NULL)
    dest = root;
  else
    dest = my_strdup(dest, argv[1]);
  env = set_old_pwd(env, bool);
  if (chdir(dest) == 0)
      return (env);
  else
    {
      my_puterr(argv[1]);
      my_puterr(" : No such file or directory\n");
      return (my_error_env(bool, env));
    }
}
