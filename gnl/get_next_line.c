/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:48:47 by soo               #+#    #+#             */
/*   Updated: 2022/04/12 13:51:38 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_newline(char *str)
{
	size_t	size;

	size = 0;
	if (str)
	{
		while (str[size])
		{
			if (str[size] == '\n')
				return (size + 1);
			++size;
		}
	}
	return (0);
}

char	*return_line(t_list *new, ssize_t size)
{
	char	*line;
	char	*tmp;
	size_t	len;

	len = find_newline(new->backup);
	if (!len && size <= 0 && new->backup)
	{
		line = ft_strdup(new->backup, 0, ft_strlen(new->backup));
		free(new->backup);
		new->backup = NULL;
		return (line);
	}
	tmp = new->backup;
	line = ft_strdup(new->backup, 0, len);
	new->backup = ft_strdup(new->backup, len, ft_strlen(new->backup) - len);
	free(tmp);
	return (line);
}

ssize_t	read_line(t_list *new, int fd)
{
	ssize_t	size;
	char	buf[BUFFER_SIZE + 1];

	size = 0;
	while (!(find_newline(new->backup)))
	{	
		if (new->flag == 1)
			return (0);
		size = read(fd, &buf, BUFFER_SIZE);
		if (size > 0 && size <= BUFFER_SIZE)
		{
			buf[size] = '\0';
			new->backup = ft_strjoin(new->backup, buf);
		}
		else
			return (size);
		if (size > 0 && size < BUFFER_SIZE)
			if (!find_newline(buf))
				new->flag = 1;
	}
	return (size);
}

char	*init(t_list *ret, int fd)
{
	t_list	*new;
	ssize_t	size;

	new = ret;
	if (new->fd != fd)
		return (NULL);
	size = read_line(new, fd);
	if (size <= 0 && new->backup == NULL)
		return (NULL);
	return (return_line(new, size));
}

char	*get_next_line(int fd)
{
	static t_list	*ret;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!ret)
	{
		ret = ft_lstnew(fd);
		if (!ret)
			return (NULL);
	}
	line = init(ret, fd);
	if (line == NULL)
	{
		free(ret);
		ret = NULL;
	}
	return (line);
}
