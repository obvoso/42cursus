/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:29:01 by soo               #+#    #+#             */
/*   Updated: 2022/04/12 13:49:03 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int				fd;
	int				flag;
	char			*backup;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1, size_t len, size_t size);
t_list	*ft_lstnew(int fd);
size_t	find_newline(char *str);
char	*return_line(t_list *new, size_t size);
ssize_t	read_line(t_list *new, int fd);
char	*init(t_list **ret, int fd);
char	*get_next_line(int fd);
t_list	**del_node(t_list **ret, int fd);

#endif
