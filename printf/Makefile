# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 12:52:29 by soo               #+#    #+#              #
#    Updated: 2022/04/17 13:42:45 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AFLAGS = rc

NAME = ft_printf.a

SRCS = ft_printf.c ft_printf_func.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	$(AR) $(AFLAGS) $^
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
clean :
	rm $(OBJS)
fclean : clean
	rm $(NAME)
re : 
	fclean all

.PHONY : all clean fclean re
