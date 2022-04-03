/*
** 42sh.h for 42SH in /home/weber_i/rendu/42SH_RELOAD
** 
** Made by Clément Weber
** Login   <weber_i@epitech.net>
** 
** Started on  Mon Sep 28 15:37:39 2015 Clément Weber
** Last update Fri Oct 23 09:42:57 2015 Guillaume Djaider Fornari
*/

#ifndef MY_42SH_H_
# define MY_42SH_H_

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termcap.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pwd.h>
#include <signal.h>
#include <limits.h>

typedef struct	s_env
{
  char		**expr;
  char		**new_path;
  char		**envN;
  char		**path;
  char		**func_simple;
  char		**func_env;
  int		i;
}		t_env;

typedef struct	s_shell
{
  char		***expr;
  char		**tab;
  char		*buffer;
  pid_t		pid;
  int		fd;
  int		bool;
  int		i;
}		t_shell;

/*
** history
*/
char	**my_historic(t_env *);
int	my_check_historic(t_env *);

/*
** builtins
*/
int	my_builtins(t_env *);
int	my_cd_back(char **);
char	**my_show_env(char **, char **,int *);
char	**my_setenv(char **, char **, int *);
char	**my_unsetenv(char **, char **, int *);
char	**my_cd(char **, char **, int *);
int	my_echo(char **);
int	my_long_echo(char *);
char	**my_functions_env();
char	**my_functions_simple();

/*
** simple_functions
*/
int	my_strcmp(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *, char *);
void	my_putchar(char);
void	my_putstr(char *);
int	my_puterr(char *);
void	my_putnbr(int);
int	my_strcmp_comp(char *, char *);
void	*my_xmalloc(int);
int	my_getnbr(const char *);
char	*my_get_write();
char	**my_error_env(int *, char **);
char	*flush(char *);

/*
** free
*/
char	**my_free(char **);
char	***my_free_expr(char ***);
char	*my_free_basic(char *);

/*
** pipe_redirection
*/
int	my_pipe_redi(t_env);
int	my_check_double_left(t_env, char **);
char	**save_double_redi_gauche(char *);
int     execute_double_redi_left(char **, char **, t_env);
int	my_delete_temp(char **);
int	my_son_redirection(char **, char *, t_env);
int	my_son_open(char *);
char	**add_redirection(char **, char *);
int	my_nb_pipe(char **, int);
char	**my_tab_pipe(int *, t_env);
int	my_last_pipe(int *, char **, t_env);
int	my_multi_pipe(int *, char **, t_env);
int	my_first_pipe(int *, char **, t_env);
int	my_parser_pipe_redi(int *, t_env);
int	my_parser_first_pipe_redi(int *, int *, t_env);
int	my_parser_multi_pipe_redi(int *, int *, t_env);
int	my_parser_last_pipe_redi(int *, int *, t_env);
int	my_redirection_right(int *, char **, t_env);
int	my_redirection_open(t_env, int);
int	my_redirection(int, t_env, char**);
int	detect_pipe(char **);

/*
** path
*/
char	**my_generate_path(char **, char *);
char	**creat_path(char *);
char	**my_find_path(char **);
char	*my_getenv(char *, char **);
char	**my_env_duplicate(char **);

/*
** strlen
*/
int	cptr_sep(char *);
int	cptr_ope(char *);
int	my_strlen(char *);
int	width_tab(char **);

/*
** execute
*/
int	my_execute(t_env *);
int     my_find_separator(int, char ***, int *);
char	*replace_exec(char *);
int	my_launcher(t_env *, char ***);

/*
** get_next_line
*/
char	*get_next_line(const int, char **);
int	set_buffer(char *, char **, int **, int);
int	modif_get_next(char *, char **, int *);
int	check_get_next(struct termios *, struct termios *, char *);
char	*unset_get_next(struct termios *, struct termios *, char *, char *);
int	set_get_next(struct termios *, struct termios *);
char	*my_realloc(char *);
char	*get_next_line_basic(const int);

/*
** autocompletion
*/
int	verif_my_autocomplete(char **, int);
int	my_autocomplete(char *);
char	*my_create_autocomplete(char *);

/*
** prompt
*/
void	display_prompt();

/*
** str_to_wordtab
*/
char	***my_str_to_wordtab(char *, char ***, int, int);
int	verif(char *, int *, char *);
int	my_parser(char **, char *, int *);
char	***verif_str(char ***);

/*
** signal
*/
int	*my_serveur();

#endif /* !MY_42SH_H_ */
