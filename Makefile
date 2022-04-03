##
## Makefile for  in /home/eizenb_m/rendu/PSU_2014_42sh
## 
## Made by max eizenberg
## Login   <eizenb_m@epitech.net>
## 
## Started on  Thu Oct  8 16:18:20 2015 max eizenberg
## Last update Thu Oct 22 17:32:43 2015 max eizenberg
##

NAME	= 42sh

SRCS	= sources/redirection/add_redirection.c \
	  sources/path/creat_path.c \
	  sources/redirection/execute_double_redi_left.c \
	  sources/get_next_line/get_next_line.c \
	  sources/main.c \
	  sources/completion/my_autocomplete.c \
	  sources/builtins/my_builtins.c \
	  sources/builtins/my_builtins_env.c \
	  sources/path/my_env_functions.c \
	  sources/simple_functions/my_free.c \
	  sources/builtins/my_getenv.c \
	  sources/simple_functions/my_io.c \
	  sources/simple_functions/my_memory_allocation.c \
	  sources/redirection/my_pipe_redirection.c \
	  sources/separator/my_separator.c \
	  sources/builtins/my_setenv.c \
	  sources/simple_functions/my_delete_temp.c \
	  sources/simple_functions/my_getnbr.c \
	  sources/redirection/my_son_redirection.c \
	  sources/simple_functions/my_strcmp_comp.c \
	  sources/simple_functions/my_strlen.c \
	  sources/parser/my_str_to_wordtab.c \
	  sources/get_next_line/my_tools_get_next_line.c \
	  sources/builtins/my_unsetenv.c \
	  sources/path/path.c \
	  sources/prompt/prompt.c \
	  sources/signal/signal.c \
	  sources/simple_functions/simple_functions.c \
	  sources/redirection/save_double_redi_gauche.c \
	  sources/redirection/verif_double_redirection_left.c \
	  sources/parser/my_str_to_wordtab_tools.c \
	  sources/launcher/my_execute.c \
	  sources/builtins/my_cd.c \
	  sources/builtins/my_cd_previous.c \
	  sources/redirection/my_verif_str.c \
	  sources/builtins/my_echo.c \
	  sources/builtins/my_echo_version.c \
	  sources/simple_functions/my_putnbr.c \
	  sources/pipe/my_pipe.c \
	  sources/pipe/my_parser_pipe_redi.c \
	  sources/simple_functions/return_error.c \
	  sources/launcher/my_launcher.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -I./include
CFLAGS	+= -W -Wextra -Wall -lncurses

CC	= gcc

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
