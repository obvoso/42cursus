# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:17:40 by soo               #+#    #+#              #
#    Updated: 2022/06/09 16:39:06 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	srcs/pipex.c
INC = -I include
OBJS = ${SRCS:.c=.o}
LIBFT = srcs/libft/libft.a
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L ./srcs/libft -l ft

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(INC)

$(LIBFT) :
	$(MAKE) -C srcs/libft all

clean :  
	$(MAKE) -C ./srcs/libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(MAKE) -C ./srcs/libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus