# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 19:59:54 by soo               #+#    #+#              #
#    Updated: 2022/07/14 20:20:34 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I include

NAME = builtin
LIBFT = srcs/libft/libft.a

CD_SRCS = srcs/cd/change_directory.c

ENV_SRCS = srcs/env/call_env.c \
			srcs/env/env.c \
			srcs/env/export.c \
			srcs/env/unset.c 

QUOTE_SRCS = srcs/quote/quote.c \
				srcs/quote/quote_utils.c \
				srcs/quote/quote_str_utils.c

UTILS_SRCS = srcs/utils.c

CD_OBJS = ${CD_SRCS:.c=.o}
ENV_OBJS = ${ENV_SRCS:.c=.o}
QUOTE_OBJS = ${QUOTE_SRCS:.c=.o}
UTILS_OBJS = ${UTILS_SRCS:.c=.o}

OBJECTS = $(CD_OBJS) $(ENV_OBJS) $(QUOTE_OBJS) $(UTILS_OBJS)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ main.c -L ./srcs/libft -l ft

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(INC)

$(LIBFT) :
	$(MAKE) -C srcs/libft all

bonus :
	make BONUS_FLAG=1
	
clean :
	$(MAKE) -C ./srcs/libft clean
	rm -f $(OBJECTS)

fclean : clean
	$(MAKE) -C ./srcs/libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re