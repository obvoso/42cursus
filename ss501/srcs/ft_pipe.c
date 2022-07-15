/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:05:12 by schoe             #+#    #+#             */
/*   Updated: 2022/07/15 21:26:58 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

void	ft_init(t_pipex *val, t_input *input)
{
	val->check = 0;
/*	if (!ft_strncmp(input->av[1], "here_doc", 9) && \
			access("here_doc", F_OK == -1))
	{
		(input->ac)--;
		val->check = 1;
	}*/
	val->exe_path = (char **)malloc(sizeof(char *) * (input->ac + 1));
	val->cmd = (char ***)malloc(sizeof(char **) * (input->ac + 1));
	val->indirec = (char ***)malloc(sizeof(char **) * (input->ac + 1));
	val->outdirec = (char ***)malloc(sizeof(char **) * (input->ac + 1));
	val->temp = (char ***)malloc(sizeof(char **) * (input->ac + 1));
	if (!val->cmd || !val->exe_path || !val->indirec || !val->outdirec || !val->temp)
		exit(1);
	val->cmd[input->ac] = NULL;
	val->exe_path[input->ac] = NULL;
	val->indirec[input->ac] = NULL;
	val->outdirec[input->ac] = NULL;
	val->temp[input->ac] = NULL;
}

int	ft_pipe(char *line, char **envp, t_env *env)
{
	t_pipex	val;
	t_input	input;
	int		i;

	i = 0;
	ft_memset(&val, 0 , sizeof(t_pipex));
	ft_memset(&input, 0, sizeof(t_input));
	val.line = ft_strdup(line);
	line = ft_trans_quot(line);
	input.av = ft_split(line, '|');
	while (input.av[i])
		i++;
	input.ac = i;
	input.ev = envp;//free 해줘야 할듯
	ft_init(&val, &input);
	val.ev = ft_ev_parsing(input.ev);
	ft_av_parsing(&input, &val);
	i = 0;
	while (val.cmd[i])
	{
		ft_tolower_str(val.cmd[i][0]);
		ft_access_check(val.cmd[i][0], &val, i);
		i++;
	}
	if (input.ac != 1)
		ft_make_pipe(&input, &val);
	i = ft_pipex(input.ac, &input, &val , env);
//	ft_pipe_clear(&val, &input);
	return (i);
}
