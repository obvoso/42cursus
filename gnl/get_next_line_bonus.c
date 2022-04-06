/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:00:28 by soo               #+#    #+#             */
/*   Updated: 2022/04/06 22:37:16 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t find_newline(char *str)
{
	size_t size;

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

char *return_line(t_list *new, size_t size)
{
	char *line;
	char *tmp;
	size_t len;

	len = find_newline(new->backup);
	if (!len && !size && new->backup)
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
		else
			return (size);
	}
	return (size);
}

char *init(t_list **ret, int fd)
{
	t_list *new;
	size_t size;

	new = *ret;
	if (!*ret)
	{
		new = ft_lstnew(fd);
		*ret = new;
	}
	else if (new->fd != fd)
	{
		while (new->fd != fd)
		{
			new = new->next;
			if (!new->next)
				break;
		}
		if (new->fd != fd && !new->next)
		{
			new->next = ft_lstnew(fd);
			new = new->next;
		}
	}
	size = read_line(new, fd);
	if (size <= 0 && new->backup == NULL)
	return (NULL);
	return (return_line(new, size));
}

t_list **del_node(t_list **ret, int fd)
{
	t_list	*p_node;
	t_list	*n_node;

	p_node = *ret;
	if (p_node->fd == fd)
	{
		*ret = p_node->next;
		free(p_node);
		p_node = NULL;
		return (ret);
	}
	while (p_node->next->fd != fd && p_node->next->next)
		p_node = p_node->next;
	if (!p_node->next->next && p_node->next->fd == fd)
	{
		free (p_node->next);
		p_node->next = NULL;
	}
	else if (p_node->next->fd == fd)
	{
		n_node = p_node->next;
		p_node->next = n_node->next;
		free(n_node);
	}
	//else 	생각하셈
	return (ret);
}

char *get_next_line(int fd)
{
	static t_list **ret;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!ret)
	{
		ret = (t_list **)malloc(sizeof(t_list *));
		if (!ret)
			return (NULL);
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