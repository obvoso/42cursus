/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:13:38 by soo               #+#    #+#             */
/*   Updated: 2022/07/09 16:55:20 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "quote.h"
#include "env.h"
//!!널가드 추가

int	del_quote_cnt(char *origin, char c)
{
	int		o_idx;
	int		cnt;
	
	o_idx = 1;
	cnt = 0;
	while (origin[o_idx + 1])
	{
		if (origin[o_idx] == c && origin[o_idx + 1] == c)
		{
			o_idx += 2;
			cnt +=2;
		}
		else
			++o_idx;
	}
	return (cnt);
}

char	*del_quote(char *origin, char c)
{
	int		i;
	int		o_idx;
	int		cnt;
	char	*ret;

	i = 0;
	cnt = del_quote_cnt(origin, c);
	if (!cnt)
		return (origin);
	ret = (char *)malloc(ft_strlen(origin) - cnt + 2);
	o_idx = 0;
	while (origin[o_idx + 1])
	{
		if (origin[o_idx] == c && origin[o_idx + 1] == c)
			o_idx += 2;
		else
			ret[i++] = origin[o_idx++];
	}
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

char	*s_line_handler(t_env *env, char **line, char **origin)
{
	char *ret;

	ret = del_quote(*origin,'\'');
	if (!ft_strncmp(ret, *origin, ft_strlen(ret)))
		return (*origin);
	free(*line);
	free(*origin);
	*origin = ft_strdup(ret);
	free(ret);
	return (*origin);
}

char	*d_line_handler(t_env *env, char **line, char **origin, int exit_code)
{
	char	*str;
	char	*ret;
	int		dollar;

	dollar = cnt_quote(*origin, '$');
	while (dollar--)
	{
		substitution_env(env, line, *origin, exit_code);
		free(*origin);
		*origin = ft_strdup(*line);
	}
	ret = del_quote(*origin, '\"');
	if (!ft_strncmp(ret, *origin, ft_strlen(ret)))
		return (*origin);
	free(*line);
	free(*origin);
	*origin = ft_strdup(ret);
	free(ret);
	return (*origin);
}

char	*quote_line(char *origin, int exit_code, t_env *env)
{
	char	*s_line;
	char	*d_line;
	
	if (find_first_charactor(origin, '\''))
	{	
		s_line = split_dup_quote(origin ,'\'');
		s_line_handler(env, &s_line, &origin);
	}
	if (find_first_charactor(origin, '\"'))
	{
		d_line = split_dup_quote(origin ,'\"');
		d_line_handler(env, &d_line, &origin, exit_code);
	}
	return (origin);
}