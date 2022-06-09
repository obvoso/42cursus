/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:51:51 by soo               #+#    #+#             */
/*   Updated: 2022/06/09 22:58:52 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envp, char **argv, char ***cmd, int idx)
{
	char	**c_path;
	int		i;

	i = 0;
	printf("%d\n", idx);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			c_path = ft_split(ft_strdup(envp[i] + 5), ':');
			if (!ft_strncmp(argv[idx], "awk", 3))
			{
				*cmd = ft_split(argv[idx], '\'');
				cmd[0][0][3] = '\0';
			}
			else
				*cmd = ft_split(argv[idx], ' ');
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
		if (!access(cmd, F_OK))
			return (cmd);
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
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

void	second_cmd(char **argv, char **envp, int pipe[])
{
	int		fd;
	char	*c_path;
	char	**path;
	char	**cmd;

	path = split_path(envp, argv, &cmd, 3);
	if (!path)
		exit (1);
	c_path = check_path(path, cmd[0]);
	if (!c_path)
		exit(1);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	if ((dup2(fd, STDOUT_FILENO) == -1) || (dup2(pipe[0], STDIN_FILENO) == -1))
		exit(1);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
	if (execve(c_path, cmd, envp) == -1)
		exit(1);
}

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
		exit(1);
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

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = 1;
	if (argc != 5)
	{
		ft_putstr_fd("Format Error : file1 \"cmd1\" \"cmd2\" file2\n", 2);
		return (1);
	}
	while (argv[i])
	{
		if (argv[i++][0] == '\0')
		{
			ft_putstr_fd("Format Error : file1 \"cmd1\" \"cmd2\" file2\n", 2);
			return (1);
		}
	}
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit (1);
	else if (pid == 0)
		first_cmd(argv, envp, fd);
	else if (pid > 0)
	{
		if (!ft_strncmp(argv[1], "/dev/urandom", 12))
			waitpid(pid, NULL, WNOHANG);
		else
			waitpid(pid, NULL, 0);
		second_cmd(argv, envp, fd);
	}
	return (0);
}
