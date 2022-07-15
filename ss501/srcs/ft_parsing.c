/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:53:16 by schoe             #+#    #+#             */
/*   Updated: 2022/07/14 13:19:35 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
static int	ft_access_check2(char *cmd, t_pipex *val, int check, int i)
{
	char	*temp;
	char	*str;
	struct stat	buf;

	ft_memset(&buf, 0, sizeof(buf));
	stat(cmd, &buf);
	if (buf.st_mode & S_IXUSR && buf.st_mode & S_IFREG)
	{
		val->exe_path[check] = cmd;
		return (0);
	}
	else
	{
		temp = ft_strjoin(val -> ev[i], "/");
		str = ft_strjoin(temp, cmd);
		free(temp);
		stat(str, &buf);
		if (buf.st_mode & S_IXUSR && buf.st_mode & S_IFREG)
		{
			val -> exe_path[check] = str;
			return (0);
		}
		free(str);
	}
	return (1);
}

int	ft_access_check(char *cmd, t_pipex *val, int check)
{
	int		i;

	i = 0;
	if (cmd == NULL)
	{
		val->exe_path[check] = NULL;
		return (0);
	}
	while (val -> ev[i])
	{
		if (ft_access_check2(cmd, val, check, i) == 0)
			return (0);
		i++;
	}
	val->exe_path[check] = NULL;
	return (0);
}

void	ft_sep_temp(t_pipex *val, int i)
{
	int	k;
	int	in;
	int	out;
	int	etc;

	k = 0;
	val->indirec[i] = (char **)malloc(sizeof(char *) * (ft_direc_count(val->temp[i], "<") * 2 + 1));
	val->outdirec[i] = (char **)malloc(sizeof(char *) * (ft_direc_count(val->temp[i], ">") * 2 + 1));
	while (val->temp[i][k])
		k++;
	val->cmd[i] = (char **)malloc(sizeof(char *) * (k + 1));
	val->indirec[i][ft_direc_count(val->temp[i], "<")*2] = NULL;
	val->outdirec[i][ft_direc_count(val->temp[i], ">")*2] = NULL;
	k = 0;
	in = 0;
	out = 0;
	etc = 0;
	while (val->temp[i][k])
	{//printf("parsing%s\n", val->temp[i][k]);
		if (val->temp[i][k][0] == '<')
		{
			if (val->temp[i][k++][1] == '<')
				val->indirec[i][in++] = "<<";
			else
				val->indirec[i][in++] = "<";
			val->indirec[i][in++] = val->temp[i][k];
		}
		else if (val->temp[i][k][0] == '>')
		{
			if (val->temp[i][k++][1] == '>')
				val->outdirec[i][out++] = ">>";
			else
				val->outdirec[i][out++] = ">";
			val->outdirec[i][out++] = val->temp[i][k];
		}
		else if (val->temp[i][k][0] == '(')
		{
			val->cmd[i][etc++] = ft_re_trans_quot(val->line, val->temp[i][k][1]);
			free(val->temp[i][k]);
		}
		else
			val->cmd[i][etc++] = val->temp[i][k];
		k++;
	}
	val->cmd[i][etc] = NULL;
}

void	ft_av_parsing(t_input *input, t_pipex *val)
{
	int	ac_temp;
	int	i;
	char	*temp;

	i = 0;
	ac_temp = input->ac;
	while (ac_temp > 0)
	{
		if (ft_strncmp(input->av[i + val->check], "awk ", 4) == 0 || \
				ft_strncmp(input->av[i + val->check], "sed ", 4) == 0)
		{
			val -> temp[i] = ft_split(input->av[i], '\'');
			temp = val->temp[i][0];
			val -> temp[i][0] = ft_strtrim(temp, " ");
			free(temp);
			ft_sep_temp(val, i);
		}
		else
		{
			val -> temp[i] = ft_split(input->av[i + val->check], ' ');
			ft_sep_temp(val, i);
		}
		i++;
		ac_temp--;
	}
}

char	**ft_ev_parsing(char **enpv)
{
	char	*str;
	char	**line;
	int		i;

	i = 0;
	while (enpv[i] != NULL)
	{
		str = ft_strnstr(enpv[i++], "PATH=", 5);
		if (str != NULL)
		{
			str = ft_strtrim(str, "PATH=");
			line = ft_split(str, ':');
			free(str);
			return (line);
		}
	}
	perror("ENV PATH error ");
	return (0);
}
