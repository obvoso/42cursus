/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:00:28 by soo               #+#    #+#             */
/*   Updated: 2022/03/31 22:08:33 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>


int	find_newline(char *buf, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == '\n')
			return (i);
		++i;
	}
	return (0);
}

t_list	**return_line(t_list **ret, int fd)
{
	t_list	*new;
	char	buf[BUFFER_SIZE + 1];
	int		buf_len;
	int		size;
	
	new = ft_lstnew(fd);
	ft_lstadd_back(ret, new);
	while ((buf_len = read(fd, &buf, BUFFER_SIZE)) > 1)
	{
		printf("buf_len = %d\n", buf_len);
		buf[buf_len] = '\0';
		printf("buf : %s\n", buf);
		while (!(size = find_newline(buf, buf_len)))
		{	

		//	if (ft_strlen(buf->backup) > buf_len)
			new->backup = ft_strjoin(new->line, buf);
			buf_len = read(fd, &buf, BUFFER_SIZE);
		}
		printf("disturb while, size = %d\n", size);
		new->backup = ft_strjoin(new->backup, buf);
		printf("new->backup %s\n", new->backup);
		new->line = ft_strdup(new->backup, size);
		new->backup = ft_strdup(&buf[size], buf_len - size);
		printf("backup : %s\n", new->backup);
		printf("newline : %s\n", new->line);
		printf("return line fuc return value : %s\n", ft_lstlast(*ret)->line);
		return (ret);
	}
	free (ret);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list		**ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = (t_list **)malloc(sizeof(t_list *) + 1);
	return_line(ret, fd);
	return (ft_lstlast(*ret)->line);
	free (ret);
	return (NULL);
}
