# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 21:49:56 by soo               #+#    #+#              #
#    Updated: 2022/05/28 15:47:04 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRCS =	srcs/main/push_swap.c \
		srcs/utils/deque_push_pop.c \
		srcs/utils/deque_utils.c \
		srcs/utils/deque_func.c \
		srcs/error/check_error.c \
		srcs/sort/array_sort.c \
		srcs/sort/deque_sort.c \

SRCS_BONUS = srcs/checker/checker_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
NAME1 = push_swap
NAME2 = checker

all : $(NAME1)

$(NAME1) : $(OBJS)
	@$(MAKE) -C ./srcs/libft all
	@$(CC) $(CFLAGS) -o $@ $^ -L ./srcs/libft -l ft


bonus : $(NAME2)

$(NAME2) : $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C ./srcs/checker all

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^
	
clean :  
	@$(MAKE) -C ./srcs/libft clean
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C ./srcs/libft fclean
	@$(MAKE) -C ./srcs/checker fclean
	@rm -f $(NAME1)

re : fclean all

.PHONY : all clean fclean re bonus