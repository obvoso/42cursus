# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 16:56:27 by soo               #+#    #+#              #
#    Updated: 2022/06/24 18:40:06 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I include

NAME = so_long
LIBFT = srcs/libft/libft.a
MLX = mlx/libmlx.a

SRCS =	srcs/main.c \
		srcs/check_map.c \
		srcs/load_map.c \
		srcs/set_image.c

OBJECTS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ -L ./srcs/libft -l ft \
							 -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(INC)

$(LIBFT) :
	$(MAKE) -C srcs/libft all
$(MLX) :
	$(MAKE) -C mlx/ all
	
clean :
	$(MAKE) -C ./srcs/libft clean
	$(MAKE) -C ./mlx clean
	rm -f $(OBJECTS)

fclean : clean
	$(MAKE) -C ./srcs/libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
