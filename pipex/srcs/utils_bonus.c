/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:12:05 by soo               #+#    #+#             */
/*   Updated: 2022/06/17 17:28:51 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_px	*px_last(t_px *head)
{
	t_px	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_px	*here_doc(int argc, char **argv, t_px **head)
{
	char	*str;
	int		fd;

	if (argc < 6)
	{
		ft_putstr_fd("Format Error\n", 2);
		exit (1);
	}
	fd = open(".tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			exit(1);
		if (!strncmp(str, argv[2], ft_strlen(argv[2])))
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
	}
	(*head)->infile = ft_strdup(".tmp");
	return (*head);
}

void	exe_first_cmd(t_px *node, char **envp)
{
	int	fd;

	if (access(node->infile, F_OK | R_OK) == -1)
		ft_printf("%s: %s\n", strerror(errno), node->infile);
	fd = open(node->infile, O_RDONLY);
	if (fd == -1)
		exit(1);
	if (dup2(fd, 0) == -1 || dup2(node->next->pipe[1], 1) == -1)
		exit(1);
	close(fd);
	close(node->pipe[1]);
	close(node->pipe[0]);
	if (execve(node->path, node->cmd, envp) == -1)
		exit(1);
}

void	exe_last_cmd(t_px *node, char **envp)
{
	int	fd;

	if (node->infile)
		fd = open(node->outfile, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(node->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	if (dup2(fd, 1) == -1 || dup2(node->pipe[0], 0) == -1)
		exit(1);
	close(fd);
	close(node->pipe[0]);
	close(node->pipe[1]);
	if (execve(node->path, node->cmd, envp) == -1)
		exit(1);
}

void	exe_process(t_px *head, int argc, char **argv, char **envp)
{
	while (head)
	{
		make_process(head, argc, argv, envp);
		head = head->next;
	}
}