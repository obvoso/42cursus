/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:48:47 by soo               #+#    #+#             */
/*   Updated: 2022/04/05 22:35:55 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t find_newline(char *str)
{
	size_t size;

	size = 0;
	if (str)
	{
		while (str[size])
		{
			if (str[size] == '\n')
			{
				return (size + 1);
			}
			++size;
		}
	}
	return (0);
}

char *return_line(t_list *new, size_t size)
{
	char *line;
	char *tmp;
	size_t len;
	int i;

	len = find_newline(new->backup);
	if (!len && !size && new->backup) //new->backup은..빼도될까
	{
		line = ft_strdup(new->backup, ft_strlen(new->backup));
		new->backup = NULL;
		return (line);
	}
	i = -1;
	tmp = (char *)malloc(ft_strlen(new->backup) + 1);
	while (new->backup[++i])
		tmp[i] = new->backup[i];
	tmp[ft_strlen(new->backup)] = '\0';
	line = ft_strdup(new->backup, len);
	new->backup = ft_strdup(&tmp[len], ft_strlen(tmp) - len);
	if (tmp)
		free(tmp);
	// line = ft_strdup(new->backup, len);
	// new->backup = ft_strdup(&new->backup[len], ft_strlen(new->backup) - len);
	return (line);
}

int read_line(t_list *new, int fd)
{
	size_t size;
	char buf[BUFFER_SIZE + 1];

	size = 0;
	while (!(find_newline(new->backup)))
	{
		size = read(fd, &buf, BUFFER_SIZE);
		if (size > 0 && size <= BUFFER_SIZE)
		{
			buf[size] = '\0';
			new->backup = ft_strjoin(new->backup, buf);
		}
		else if ((!size && new->backup == NULL) || size > BUFFER_SIZE)
		{
			return (0);
		}
		else
			return (size);
	}
	return (size);
}

char *init(t_list *ret, int fd)
{
	t_list *new;
	size_t size;

	new = ret;
	if (new->fd != fd)
		return (NULL);
	size = read_line(new, fd);
	if (size <= 0 && new->backup == NULL)
		return (NULL);
	return (return_line(new, size));
}

char *get_next_line(int fd)
{
	static t_list *ret;
	char *line;

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
		return (NULL);
	}
	return (line);
}