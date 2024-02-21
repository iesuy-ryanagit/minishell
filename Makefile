NAME = minishell
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = main.c \
       handle/signal_handler.c \
       lexparse/check_char.c \
       lexparse/check_gram.c \
       lexparse/check_str.c \
       lexparse/env_list_base.c \
       lexparse/env_make.c \
       lexparse/exp.c \
       lexparse/exp_env_list.c \
       lexparse/exp_help.c \
       lexparse/exp_sup.c \
       lexparse/free_end.c \
       lexparse/get_count.c \
       lexparse/lexparse.c \
       lexparse/list.c \
       lexparse/parse.c \
       lexparse/relibft.c \
       lexparse/show_errmessage.c \
       lexparse/word_roop.c \
       lexparse/word_split.c \
	   lexparse/triadd.c \
       builtin/built.c \
       builtin/bultin_error.c \
       builtin/cd.c \
       builtin/echo.c \
       builtin/env.c \
       builtin/exit.c \
       builtin/exit_help.c \
       builtin/export.c \
       builtin/pwd.c \
       builtin/unset.c \
	   execve/add.c \
       execve/base.c \
       execve/cris.c \
       execve/do_execve_bc.c \
       execve/do_execve.c \
       execve/do_other.c \
       execve/help.c \
       execve/helpc.c \
       execve/helpipe.c \
       execve/heredoc.c \
       execve/heredoc_help.c \
       execve/mini.c \
       execve/pipe.c \
       execve/pipehelp.c \
       execve/sidan.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lreadline -lhistory -L$(LIBFT_PATH) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re