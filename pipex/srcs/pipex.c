/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:51:51 by soo               #+#    #+#             */
/*   Updated: 2022/06/12 20:59:19 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_cmd(char **argv, char **envp, int pipe[])
{
	int		fd;
	char	*c_path;
	char	**path;
	char	**cmd;

	if (access(argv[1], F_OK | R_OK) == -1)
		ft_printf("%s: %s\n", strerror(errno), argv[1]);
	path = split_path(envp, argv, &cmd, 2);
	if (!path)
		exit(1);
	c_path = check_path(path, cmd[0]);
	if (!c_path)
		exit(127);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipe[1], STDOUT_FILENO) == -1)
		exit(1);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

static void	second_cmd(char **argv, char **envp, int pipe[])
{
	int		fd;
	char	*c_path;
	char	**path;
	char	**cmd;

	path = split_path(envp, argv, &cmd, 3);
	if (!path)
		exit(1);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	c_path = check_path(path, cmd[0]);
	if (!c_path)
		exit(127);
	if (dup2(fd, STDOUT_FILENO) == -1 || (dup2(pipe[0], STDIN_FILENO) == -1))
		exit(1);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

static int	first_child(char **argv, char **envp, int pipe[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		first_cmd(argv, envp, pipe);
	else if (pid > 0)
	{
		if (!ft_strncmp(argv[1], "/dev/urandom", 12))
			waitpid(pid, NULL, WNOHANG);
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}

static int	second_child(char **argv, char **envp, int pipe[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		second_cmd(argv, envp, pipe);
	else if (pid > 0)
	{
		close(pipe[0]);
		close(pipe[1]);
		waitpid(pid, NULL, 0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (check_arg(argc, argv))
		return (1);
	if (pipe(fd) == -1)
		return (1);
	if (first_child(argv, envp, fd))
		exit(1);
	if (second_child(argv, envp, fd))
		exit(1);
	return (0);
}
