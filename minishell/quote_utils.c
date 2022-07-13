/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:07:16 by soo               #+#    #+#             */
/*   Updated: 2022/07/13 16:52:34 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"
#include "env.h"
#include <stdio.h>

char	*find_exit_code(char **sep_str, int exit_code)
{
	int		i;
	char	*str_exit_code;

	i = 0;
	while (sep_str[1][i + 1])
	{
		if (sep_str[1][i] == '$' && sep_str[1][i + 1] == '?')
		{
			str_exit_code = ft_itoa(exit_code);
			free(sep_str[1]);
			sep_str[1] = ft_strdup(str_exit_code);
			free(str_exit_code);
			break;
		}
		++i;
	}
	return (sep_str[1]);
}

char *find_env(t_env *env, char *str)
{
	t_env	*now;
	char	*sub_str;

	now = env;
	while (now->next)
	{
		if (!ft_strncmp(now->key, str, ft_strlen(str) + 1))
			{
				if (now->unset_flag)
					return (ft_strdup(""));
				sub_str = ft_strdup(now->value);
				return (sub_str);
			}
		now = now->next;
	}
	return (NULL);
}

int	cnt_c(char *line, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			++cnt;
		++i;
	}
	return (cnt);
}



int	find_first_c(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int	find_last_c(char *line, char c)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		--i;
	}
	return (0);
}
