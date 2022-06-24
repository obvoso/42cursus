/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:00:28 by soo               #+#    #+#             */
/*   Updated: 2022/05/27 22:46:05 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*return_line(t_glist *new, size_t size)
{
	char	*line;
	char	*tmp;
	size_t	len;

	len = find_newline(new->backup);
	if (!len && !size && new->backup)
	{
		line = gnl_strdup(new->backup, 0, gnl_strlen(new->backup));
		free(new->backup);
		new->backup = NULL;
		return (line);
	}
	tmp = new->backup;
	line = gnl_strdup(new->backup, 0, len);
	new->backup = gnl_strdup(new->backup, len, gnl_strlen(new->backup) - len);
	free(tmp);
	return (line);
}

ssize_t	read_line(t_glist *new, int fd)
{
	size_t	size;
	char	buf[BUFFER_SIZE + 1];

	size = 0;
	if (!new)
		return (0);
	while (!(find_newline(new->backup)))
	{
		if (new->flag == 1)
			return (0);
		size = read(fd, &buf, BUFFER_SIZE);
		if (size > 0 && size <= BUFFER_SIZE)
		{
			buf[size] = '\0';
			new->backup = gnl_strjoin(new->backup, buf);
		}
		else
			return (size);
		if (size > 0 && size < BUFFER_SIZE)
			if (!find_newline(buf))
				new->flag = 1;
	}
	return (size);
}

char	*init(t_glist **ret, int fd)
{
	t_glist	*new;
	size_t	size;

	new = *ret;
	if (!*ret)
	{
		new = gnl_lstnew(fd);
		*ret = new;
	}
	else if (new->fd != fd)
	{
		while (new->fd != fd && new->next)
			new = new->next;
		if (new->fd != fd && !new->next)
		{
			new->next = gnl_lstnew(fd);
			new = new->next;
		}
	}
	size = read_line(new, fd);
	if (size <= 0 && new->backup == NULL)
		return (NULL);
	return (return_line(new, size));
}

t_glist	**del_node(t_glist **ret, int fd)
{
	t_glist	*p_node;
	t_glist	*n_node;

	p_node = *ret;
	if (p_node->fd == fd)
	{
		*ret = p_node->next;
		free(p_node);
		return (ret);
	}
	while (p_node->next->fd != fd && p_node->next->next)
		p_node = p_node->next;
	if (p_node->next->fd == fd && !p_node->next->next)
	{
		n_node = p_node->next;
		free (n_node);
		p_node->next = NULL;
	}
	else if (p_node->next->fd == fd && p_node->next->next)
	{
		n_node = p_node->next;
		p_node->next = n_node->next;
		free(n_node);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_glist	**ret;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!ret)
	{
		ret = (t_glist **)malloc(sizeof(t_glist *));
		if (!ret)
			return (NULL);
		*ret = NULL;
	}
	line = init(ret, fd);
	if (line == NULL)
	{
		del_node(ret, fd);
		if (!*ret)
		{
			free(ret);
			ret = NULL;
		}
		return (NULL);
	}
	return (line);
}
