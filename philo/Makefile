# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 00:19:38 by soo               #+#    #+#              #
#    Updated: 2022/09/18 00:20:50 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS =	main.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^ 

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ 
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 
