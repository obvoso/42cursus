/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:02:55 by soo               #+#    #+#             */
/*   Updated: 2022/06/17 20:55:19 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_process(t_px *node, int argc, char **argv, char **envp)
{
	node->pid = fork();
	if (node->pid == -1)
		exit(1);
	else if (node->pid == 0)
		exe_cmd(node, argc, argv, envp);
	else if (node->pid > 0)
	{
		close(node->pipe[0]);
		close(node->pipe[1]);
		if (node->num == 1 && !ft_strncmp(argv[1], "/dev/urandom", 12))
			waitpid(node->pid, NULL, WNOHANG);
		else
			waitpid(node->pid, NULL, 0);
		if (node->num == 1 && !ft_strncmp(node->infile, ".tmp", 4))
			unlink(node->infile);
	}
}

void	exe_cmd(t_px *node, int argc, char **argv, char **envp)
{
	if (node->num == 1)
		exe_first_cmd(node, envp);
	else if (node == px_last(node))
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
			node->infile = ft_strdup(".tmp");
		node->outfile = ft_strdup(argv[argc - 1]);
		exe_last_cmd(node, envp);
	}
	else
	{
		if (dup2(node->pipe[0], 0) == -1 || dup2(node->next->pipe[1], 1) == -1)
			exit(1);
		close(node->pipe[0]);
		close(node->pipe[1]);
		if (execve(node->path, node->cmd, envp) == -1)
			exit(1);
	}	
}

t_px	*px_head_init(t_px **head, char **av, char **ep, int num)
{
	if (pipe((*head)->pipe) == -1)
		exit(1);
	(*head)->num = num;
	if ((*head)->infile)
		(*head)->c_path = split_path(ep, av, &(*head)->cmd, (*head)->num + 2);
	else
	{
		(*head)->c_path = split_path(ep, av, &(*head)->cmd, (*head)->num + 1);
		(*head)->infile = ft_strdup(av[1]);
	}
	if (!(*head)->c_path)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
	(*head)->path = check_path((*head)->c_path, (*head)->cmd[0]);
	if (!(*head)->path)
		exit(127);
	return (*head);
}

t_px	*px_node_init(t_px **head, char **av, char **ep, int num)
{
	t_px	*new;
	t_px	*tmp;

	if ((*head)->num == 0)
		px_head_init(head, av, ep, num);
	else
	{
		new = (t_px *)malloc(sizeof(t_px));
		if (pipe(new->pipe) == -1)
			exit(1);
		new->num = num;
		if (!ft_strncmp((*head)->infile, ".tmp", 4))
		{
			new->c_path = (split_path(ep, av, &new->cmd, new->num + 2));
			new->path = check_path(new->c_path, new->cmd[0]);
		}
		else
		{
			new->c_path = (split_path(ep, av, &new->cmd, new->num + 1));
			new->path = check_path(new->c_path, new->cmd[0]);
		}
		tmp = px_last(*head);
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	return (*head);
}

int	main(int argc, char **argv, char **envp)
{
	int		num;
	int		cmd_cnt;
	t_px	*head;

	if (check_argv(argv, argc))
		return (1);
	head = (t_px *)malloc(sizeof(t_px));
	if (!head)
		exit(1);
	ft_memset(head, 0, sizeof(t_px));
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		here_doc(argc, argv, &head);
		cmd_cnt = argc - 4;
	}
	else
		cmd_cnt = argc - 3;
	num = 1;
	while (cmd_cnt--)
		px_node_init(&head, argv, envp, num++);
	exe_process(head, argc, argv, envp);
	return (0);
}
