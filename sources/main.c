/*
** main.c for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 14:59:37 2015 Clément Weber
** Last update Thu Oct 22 17:35:52 2015 max eizenberg
*/

#include "my_42sh.h"
#include "error.h"

static	int	my_exit(char ***expr, t_env shell)
{
  t_shell	value;

  value.bool = (expr[0][1]) != NULL
    ? my_getnbr(expr[0][1]) : 0;
  my_free_expr(expr);
  my_free(shell.path);
  my_free(shell.func_simple);
  my_free(shell.func_env);
  return (value.bool);
}

static char	***my_call(char *buffer)
{
  char		***expr;
  int		a;
  int		b;

  expr = NULL;
  a = 0;
  b = 0;
  expr = my_str_to_wordtab(buffer, expr, a, b);
  return (expr);
}

static int	my_shell(t_env *shell)
{
  t_shell	tab;

  while (42)
    {
      display_prompt();
      if ((tab.buffer = get_next_line(0, shell->envN)) == NULL)
	return (0);
      if ((tab.expr = my_call(tab.buffer)) != NULL &&
	  tab.buffer[0] != '\t' && (tab.expr[0] != NULL))
	{
	  flush(tab.buffer);
	  my_free_basic(tab.buffer);
	  if ((my_strcmp(tab.expr[0][0], "exit") == 0))
	    return (my_exit(tab.expr, *shell));
	  if ((tab.expr = verif_str(tab.expr)) == NULL)
	    return (-1);
	  if (my_launcher(shell, tab.expr) == -1)
	    return (-1);
	  tab.expr = my_free_expr(tab.expr);
	}
    }
  return (0);
}

static int	my_first_init(t_env *set, char **env)
{
  set->envN = my_env_duplicate(env);
  if (set->envN == NULL)
    {
      set->func_simple = my_functions_simple();
      set->func_env = my_functions_env();
      return (my_puterr(COPY_ENV_E));
    }
  set->func_simple = my_functions_simple();
  set->func_env = my_functions_env();
  set->path = my_find_path(set->envN);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_env		set;

  (void) argc;
  (void) argv;
  my_first_init(&set, env);
  my_serveur();
  return (my_shell(&set));
}
