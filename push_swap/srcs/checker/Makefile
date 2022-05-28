# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 22:50:56 by soo               #+#    #+#              #
#    Updated: 2022/05/28 15:53:02 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../include
SRCS =	../utils/deque_push_pop.c \
		../utils/deque_utils.c \
		../utils/deque_func.c \
		../error/check_error.c \
		../sort/array_sort.c \
		../sort/deque_sort.c \

SRCS_BONUS = checker_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
NAME2 = checker

all : $(NAME2)

$(NAME2) : $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C ../libft all
	@$(CC) $(CFLAGS) -o $@ $^ -L ../libft -l ft
	@mv $(NAME2) ../../

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^
	
clean :  
	@$(MAKE) -C ../libft clean
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C ../libft fclean
	@rm -f ../../$(NAME2)

re : fclean all

.PHONY : all clean fclean re