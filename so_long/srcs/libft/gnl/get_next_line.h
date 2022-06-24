/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:53:04 by soo               #+#    #+#             */
/*   Updated: 2022/06/07 19:35:21 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_glist
{
	int				fd;
	int				flag;
	char			*backup;
	struct s_glist	*next;
}	t_glist;

char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_strdup(char *s1, size_t len, size_t size);
t_glist	*gnl_lstnew(int fd);
size_t	find_newline(char *str);
char	*return_line(t_glist *new, ssize_t size);
ssize_t	read_line(t_glist *new, int fd);
char	*init(t_glist *ret, int fd);
char	*get_next_line(int fd);

#endif
