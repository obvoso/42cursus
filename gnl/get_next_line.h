/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:53:04 by soo               #+#    #+#             */
/*   Updated: 2022/04/08 16:54:47 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1, size_t len, size_t size);
t_list	*ft_lstnew(int fd);
size_t	find_newline(char *str);
char	*return_line(t_list *new, size_t size);
int		read_line(t_list *new, int fd);
char	*init(t_list *ret, int fd);
char	*get_next_line(int fd);

#endif