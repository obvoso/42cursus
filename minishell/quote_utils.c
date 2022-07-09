/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:07:16 by soo               #+#    #+#             */
/*   Updated: 2022/07/08 20:40:05 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"
#include "env.h"

char *find_env(t_env *env, char *str, int exit_code)
{
	t_env	*now;
	char	*sub_str;

	if (str[1] == '?' && str[2] == ' ')
		return (ft_itoa(exit_code));
	now = env;
	while (now->next)
	{
		if (!ft_strncmp(now->key, str, ft_strlen(now->key)) \
			&& ft_strlen(now->key) == ft_strlen(str))
			{
				sub_str = ft_strdup(now->value);
				return (sub_str);
			}
		// if (!now->next->next)
		// 	break;
		now = now->next;
	}
	return (NULL);
}

int	cnt_quote(char *line, char c)
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

int	find_first_charactor(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		++i;
	}
	return (0);
}

int	find_last_charactor(char *line, char c)
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
