/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:29:01 by soo               #+#    #+#             */
/*   Updated: 2022/04/01 21:47:10 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif
/*
# ifndef OPEN_MAX
#define OPEN_MAX 256
# endif
*/
typedef struct	s_list
{
	int	fd;
	char *line;
	char *backup;
	struct s_list *next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr (const char *s, int c);
size_t	ft_strlen (const char *s);
char	*ft_strdup (char *s1, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int fd);;

# endif
