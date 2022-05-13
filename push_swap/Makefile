# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 21:49:56 by soo               #+#    #+#              #
#    Updated: 2022/05/13 15:56:03 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
SCRS = push_swap.c deque_push_pop.c deque_utils.c deque_func.c
OBJS = ${SCRS:.c=.o}
NAME = libpushswap.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft all
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :  
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re