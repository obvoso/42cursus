/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:51:51 by soo               #+#    #+#             */
/*   Updated: 2022/06/10 23:07:19 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char **argv, char **envp, int pipe[])
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
	if ((dup2(fd, STDIN_FILENO) == -1) || (dup2(pipe[1], STDOUT_FILENO) == -1))
		exit(1);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

void	second_cmd(char **argv, char **envp, int pipe[])
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
	if ((dup2(fd, STDOUT_FILENO) == -1) || (dup2(pipe[0], STDIN_FILENO) == -1))
		exit(1);
	write(1, "1\n", 2);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

void	second_child(char **argv, char **envp, int fd[])
{
		pid_t	pid;

		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
		{
			second_cmd(argv, envp, fd);
		}
		else
			waitpid(pid, NULL, 0);
}
/*
int	ddal_process(char **argv, char **envp, int fd[])
{
		int	pid;

		pid = fork();
		if (pid == -1)
			return (1);
		else if (pid == 0)
			first_cmd(argv, envp, fd);
		else if (pid > 0)
		{
			if (!ft_strncmp(argv[1], "/dev/urandom", 12))
				waitpid(pid, NULL, WNOHANG);
			else
				waitpid(pid, NULL, 0);
			return (second_cmd(argv, envp, fd));
		}
}
*/
int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (check_arg(argc, argv))
		return (1);
	 if (pipe(fd) == -1)
	 	return (1);
	pid = fork();
	if (pid == -1)
		return  (1);
	else if (pid == 0)
		first_cmd(argv, envp, fd);
	else
	{
		if (!ft_strncmp(argv[1], "/dev/urandom", 12))
			waitpid(pid, NULL, WNOHANG);
		else
			waitpid(pid, NULL, 0);
		second_child(argv, envp, fd);
	}
	return (0);
}
