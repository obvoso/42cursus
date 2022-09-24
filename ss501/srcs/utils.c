/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:09:59 by soo               #+#    #+#             */
/*   Updated: 2022/07/15 19:56:18 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

char	**line_format(char *line, char *cmd)
{
	char	**str;
	char	**ret;
	int		i;

	i = 1;
	ret = (char **)malloc(sizeof(char *) * 3);
	str = ft_split(line, ' ');
	if (!ft_strncmp(str[0], cmd, ft_strlen(cmd + 1)))
		ret[0] = ft_strdup(str[0]);
	else
		return (NULL); // error command not found
	if (line[ft_strlen(ret[0])] == '\0')
		ret[1] = ft_strdup("");
	else
		ret[1] = ft_strdup(&line[ft_strlen(ret[0]) + 1]);
	ret[2] = NULL;
	str_free(str);
	return (ret);
}

int	format_check(char *line)
{
	int		i;
	int		e_flag;

	i = 0;
	e_flag = 0;
	if (line[0] >= '0' && line[0] <= '9')
		return (0);
	if (line[0] == '=')
		return (0);
	while (line[i])
	{
		if (line[i] == '=')
		{
			e_flag = 1;
			break;
		}
		++i;
	}
	if (e_flag)
		return (1);
	else if (!e_flag)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == ' ')
				return (0);
			++i;
		}
	}
	if (i == 0)
		return (0);
	return (1);
}

void str_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}