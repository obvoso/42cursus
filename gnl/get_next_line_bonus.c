/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:00:28 by soo               #+#    #+#             */
/*   Updated: 2022/04/02 23:05:56 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int find_newline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		++i;
	}
	return (0);
}

t_list *return_line(t_list **ret, int fd)
{
	t_list *new;
	char *tmp;
	char buf[BUFFER_SIZE + 1];
	int buf_len;
	int size;

	if (!*ret)
		*ret = ft_lstnew(fd);
	new = *ret;
	while (new->fd != fd &&new->next)
		new = new->next;
	if (!new->next &&new->fd != fd)
		new = ft_lstnew(fd);
	if (!new->backup)
	{
		buf_len = read(fd, &buf, BUFFER_SIZE);
		new->backup = ft_strjoin(new->backup, buf);
		if (buf_len > 1)
		{
			while (!(size = find_newline(new->backup)))
			{
				tmp = new->backup;
				buf_len = read(fd, &buf, BUFFER_SIZE);
				new->backup = ft_strjoin(new->backup, buf);
				free(tmp);
			}
			printf("disturb while, size = %d\n", size);
			printf("new->backup :%s\n", new->backup);
			tmp = new->line;
			new->line = ft_strdup(new->backup, size);
			free(tmp);
			tmp = new->backup;
			new->backup = ft_strdup(&buf[size], buf_len - size);
			free(tmp);
			printf("after trim backup :%s\n", new->backup);
			printf("after trim newline :%s\n", new->line);
			return (new);
		}
	}
	else
	{
		printf("else newbackup :%s\n", new->backup);
		buf_len = ft_strlen(new->backup);
		if (buf_len > 1)
		{
			while (!(size = find_newline(new->backup)))
			{
				printf("%d\n", size);
				tmp = new->backup;
				buf_len = read(fd, &buf, BUFFER_SIZE);
				new->backup = ft_strjoin(new->backup, buf);
				free(tmp);
			}

			printf("disturb while, size = %d\n", size);
			printf("new->backup: %s\n", new->backup);
			tmp = new->line;
			new->line = ft_strdup(new->backup, size);
			printf("1after trim newline : %s\n", new->line);
			free(tmp);
			tmp = new->backup;
			printf("before trim backup : %s\n", new->backup);
			printf("2after trim newline : %s\n", new->line);
			tmp = new->backup;
			new->backup = ft_strdup(&(new->backup)[size], buf_len - size);
			printf("3after trim newline : %s\n", new->line);
			free(tmp);
			printf("after trim backup : %s\n", new->backup);
			printf("a4fter trim newline : %s\n", new->line);
			return (new);
		}
	}
	printf("buf_len = %d\n", buf_len);
	if (buf_len > 1)
	{
	}
	free(ret);
	return (NULL);
}

char *get_next_line(int fd)
{
	static t_list **ret;
	t_list *p_node;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!ret)
		ret = (t_list **)malloc(sizeof(t_list *));
	printf("\n호출 몇번 되는데\n\n");
	p_node = return_line(ret, fd);
	if (p_node)
	{
		printf("!!p_node%s\n", p_node->line);
		return (p_node->line);
	}
	return (NULL);
}
