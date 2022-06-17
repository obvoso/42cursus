# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:17:40 by soo               #+#    #+#              #
#    Updated: 2022/06/17 16:59:11 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I include

NAME = pipex
LIBFT = srcs/libft/libft.a

SRCS =	srcs/pipex.c \
		srcs/error.c \
		srcs/path.c

BONUS_SRCS = srcs/pipex_bonus.c \
			 srcs/utils_bonus.c \
			 srcs/path.c \
			 srcs/error.c \

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

ifdef BONUS_FLAG
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L ./srcs/libft -l ft

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(INC)

$(LIBFT) :
	$(MAKE) -C srcs/libft all

bonus :
	make BONUS_FLAG=1
	
clean :
	$(MAKE) -C ./srcs/libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(MAKE) -C ./srcs/libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus