/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:13:38 by soo               #+#    #+#             */
/*   Updated: 2022/07/07 22:39:43 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "quote.h"
#include "env.h"
//!!널가드 추가

char	*del_quote(char *line, char *str, char c)
{
	int	i;
	int	line_i;

	i = 0;
	line_i = 1;
	while (line[line_i])
	{
		if (line[line_i] == c && line[line_i + 1] == c)
			line_i += 2;
		else
			str[i++] = line[line_i++];
	}
	str[i++] = '\'';
	str[i] = '\0';
	return (str);
}

char	*s_line_handler(t_env *env, char **line, char *origin, int exit_code)
{

	//del_quote(origin, *line, '\"');
	return (*line);
}

char	*d_line_handler(t_env *env, char **line, char *origin, int exit_code)
{
	char	*str;
	int		doller;

	doller = cnt_quote(*line, '$');
	while (doller--)
		substitution_env(env, *line, origin, exit_code);
	//del_quote(origin, *line, '\"');
	// str_free(line);
	return (*line);
}

char	*quote_line(char *origin, int exit_code, t_env *env)
{
	char	*s_line;
	char	*d_line;

	if (find_first_charactor(origin, '\''))
	{
		s_line = split_dup_quote(origin ,'\'');
		return (s_line_handler(env, &s_line, origin, exit_code)); // 멀로 받을지 생각해보렴
	}
	if (find_first_charactor(origin, '\"'))
	{
		// 앞 명령어 떼어서 저장해뒀다가 마지막에 붙여서 리턴해야됨
		d_line = split_dup_quote(origin, '\"');
		return (d_line_handler(env, &d_line, origin, exit_code));
	}
	return (origin);
}