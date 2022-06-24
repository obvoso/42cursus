# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:13:23 by soo               #+#    #+#              #
#    Updated: 2022/06/22 17:57:09 by soo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c \
	   ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	   ft_strlcat.c ft_toupper.c ft_tolower.c \
	   ft_strchr.c ft_strrchr.c ft_strncmp.c \
	   ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c \
			 ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			 ft_lstmap.c

SRCS_GNL = gnl/get_next_line.c \
		   gnl/get_next_line_utils.c \
		   gnl/get_next_line_bonus.c \
		   gnl/get_next_line_utils_bonus.c

SRCS_PRINTF = printf/ft_printf.c \
			  printf/ft_printf_func.c \
			  printf/ft_printf_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

ifdef WITH_BONUS
  OBJECTS = $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF)
else
  OBJECTS = $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ 

bonus :
	make WITH_BONUS=1

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re bonus
