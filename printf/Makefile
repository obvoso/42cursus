# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 12:52:29 by soo               #+#    #+#              #
#    Updated: 2022/04/18 17:28:43 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar
AFLAGS = rcs

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_func.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(AR) $(AFLAGS) $@ $^
%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ -I ft_printf.h
clean :
	rm $(OBJS)
fclean : clean
	rm $(NAME)
	
re : fclean all

