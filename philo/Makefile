# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 00:19:38 by soo               #+#    #+#              #
#    Updated: 2022/10/07 17:45:12 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS =	srcs/main.c \
		srcs/init.c \
		srcs/action.c \
		srcs/print.c \
		srcs/time.c \
		srcs/check.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -Iinclude
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 
