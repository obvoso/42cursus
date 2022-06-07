/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:51:51 by soo               #+#    #+#             */
/*   Updated: 2022/06/07 22:47:55 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envp)
{
	char	**c_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			c_path = ft_split(ft_strdup(envp[i] + 5), ':');
			return (c_path);
		}
		++i;
	}
	return (NULL);
}

char	*check_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*c_path;

	i = 0;
	if (*cmd == '/')
	{
		if (!access(cmd, F_OK))
			return (cmd);
		return (NULL);
	}
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		c_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(c_path, F_OK))
			return (c_path);
		++i;
		free(c_path);
	}
	return (NULL);
}

void	second_cmd(char **argv, char **envp, int pipe[])
{
	int		fd;
	char	*c_path;
	char	**path;
	char	**cmd;

	path = split_path(envp);
	if (!path)
		exit (1);
	cmd = ft_split(argv[3], ' ');
	c_path = check_path(path, cmd[0]);
	if (!c_path)
		ft_printf("command not found: %s\n", cmd[0]);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(1);
	close(fd);
	close(pipe[1]);
	if (dup2(pipe[0], STDIN_FILENO) == -1)
		exit(1);
	close(pipe[0]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

void	first_cmd(char **argv, char **envp, int pipe[])
{
	int		fd;
	char	*c_path;
	char	**path;
	char	**cmd;

	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
	{
		ft_printf("Error: no such file or directory: %s\n", argv[1]);
		exit (1);
	}
	path = split_path(envp);
	if (!path)
		exit (1);
	cmd = ft_split(argv[2], ' ');
	c_path = check_path(path, cmd[0]);
	if (!c_path)
		ft_printf("command not found: %s\n", cmd[0]);
	close(pipe[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(1);
	close(fd);
	if (dup2(pipe[1], STDOUT_FILENO) == -1)
		exit(1);
	close(pipe[1]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit (1);
	else if (pid == 0)
		first_cmd(argv, envp, fd);
	else if (pid > 0)
	{
		waitpid(pid, NULL, WNOWAIT);
		second_cmd(argv, envp, fd);
	}
}
