/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:57:29 by soo               #+#    #+#             */
/*   Updated: 2022/06/17 17:13:04 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envp, char **argv, char ***cmd, int idx)
{
	char	**c_path;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tmp = ft_strdup(envp[i] + 5);
			c_path = ft_split(tmp, ':');
			free(tmp);
			if (!ft_strncmp(argv[idx], "awk", 3) \
				|| (!ft_strncmp(argv[idx], "sed", 3)))
				split_path_awk(argv, cmd, idx);
			else
				*cmd = ft_split(argv[idx], ' ');
			return (c_path);
		}
		++i;
	}
	return (NULL);
}

char	***split_path_awk(char **argv, char ***cmd, int idx)
{
	*cmd = ft_split(argv[idx], '\'');
	cmd[0][0][3] = '\0';
	return (cmd);
}

char	*check_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*c_path;

	if (path && *path)
	{
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
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}
