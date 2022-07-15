# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 17:04:36 by schoe             #+#    #+#              #
#    Updated: 2022/07/14 13:50:52 by schoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
       ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
       ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
       ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
       ft_tolower.c ft_toupper.c ft_lstadd_back.c ft_lstadd_front.c \
       ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
       ft_lstnew.c ft_lstsize.c ft_ultoa.c ft_printf.c ft_printf_utils.c \
       ft_u_convert_base.c get_next_line.c ft_eprintf.c ft_eprintf_utils.c \
       ft_strndup.c ft_strjoin_free.c
OBJS = ${SRCS:.c=.o}
RM = rm -f
INCLUDE = -I../includes
NAME = ../libft.a

all : $(NAME)

$(NAME) : ${OBJS}
		ar -crs $(NAME) ${OBJS}

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} $(NAME)

re : fclean all

.PHONY: all clean fclean re
