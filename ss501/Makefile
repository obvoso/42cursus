
CFLAGS = -Wall -Wextra -Werror -Iincludes -g -fsanitize=address
CC = cc

# brew info readline
# 인텔 맥 ( 클러스터 PC X )
# READLINE_LIB 	= -lreadline -L/usr/local/opt/readline/lib
# READLINE_INC	= -I/usr/local/opt/readline/include

# 인텔 맥 ( 클러스터 PC O )
READLINE_LIB 	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
READLINE_INC	= -I /Users/$(USER)/.brew/opt/readline/include

# M1 맥 ( 클러스터 PC X )
# READLINE_LIB	= -lreadline -L/opt/homebrew/opt/readline/lib
# READLINE_INC	= -I/opt/homebrew/opt/readline/include

SRCS = srcs/main.c srcs/ft_cmd.c srcs/ft_parsing.c srcs/ft_error_check.c \
	   srcs/ft_pipe_utils.c srcs/ft_pipe.c srcs/ft_dire_file.c srcs/ft_utils.c \
	   srcs/ft_echo.c srcs/ft_free.c srcs/ft_syntax.c srcs/ft_trans_quot.c \
	   srcs/ft_make_here_doc.c

S_SRCS = srcs/cd/change_directory.c \
		srcs/env/call_env.c \
		srcs/env/env.c \
		srcs/env/export.c \
		srcs/env/unset.c \
		srcs/quote/quote.c \
		srcs/quote/quote_utils.c \
		srcs/quote/quote_str_utils.c \
		srcs/utils.c srcs/env/env_arr.c

LIBFT = libft.a

NAME = minishell

C_OBJS = $(SRCS:.c=.o)
S_OBJS = $(S_SRCS:.c=.o)

OBJS = $(C_OBJS) $(S_OBJS)

all:  $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE_INC) $(READLINE_LIB)

$(LIBFT):
	@make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean:
	@make clean -C libft/
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) $(OBJS)

re: fclean all
