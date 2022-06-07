# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:17:40 by soo               #+#    #+#              #
#    Updated: 2022/06/07 22:47:56 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRCS =	srcs/pipex.c
OBJS = ${SRCS:.c=.o}
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C ./srcs/libft all
	@$(CC) $(CFLAGS) -o $@ $^ -L ./srcs/libft -l ft

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^
	
clean :  
	@$(MAKE) -C ./srcs/libft clean
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C ./srcs/libft fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus