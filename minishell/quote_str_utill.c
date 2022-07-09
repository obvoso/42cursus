/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_str_utill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:15 by soo               #+#    #+#             */
/*   Updated: 2022/07/08 20:40:06 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "quote.h"
#include "env.h"
//!!널가드 추가

char	*arrange_str_cpy(char *ret, char *s1, char *s2, char *s3)
{
	int	i;

	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	while (*s3)
		ret[i++] = *s3++;
	ret[i] = '\0';
	return (ret);
}

char	*arrange_str(char **sep_str, char *origin, char **line)
{
	char	**split_line;
	int		back;

	split_line = (char **)malloc(sizeof(char *) * 3);
	split_line[0] = ft_strndup(origin, find_first_charactor(origin, '$'));
	back = find_first_charactor(&origin[ft_strlen(split_line[0])], '\"') + ft_strlen(split_line[0]);
	split_line[1] = ft_strdup(&origin[back]);
	split_line[2] = NULL;
	free(*line);
	*line = (char *)malloc(ft_strlen(split_line[0]) + \
			ft_strlen(split_line[1]) + ft_strlen(sep_str[1]) + 1);
	*line = arrange_str_cpy(*line, split_line[0], sep_str[1], split_line[1]);
	str_free(split_line);
	return (*line);
}

char	*substitution_env(t_env *env, char **line, char *origin, int exit_code)
{
	char	**sep_str;
	int		dollar;
	int		end;
	int		i;

	sep_str = (char **)malloc(sizeof(char *) * 3);
	sep_str[2] = NULL;
	
	dollar = find_first_charactor(*line, '$');
	end = find_first_charactor(&line[0][dollar], '\"') + dollar;
	sep_str[0] = (char *)malloc(end - dollar + 1);
	i = 0;
	sep_str[0] = ft_strndup(&line[0][dollar + 1], end - dollar - 1); // 치환할 키
	sep_str[1] = find_env(env, sep_str[0], exit_code); // 치환된 value
	arrange_str(sep_str, origin, line); // 치환 문자 기준 앞 문자열 + 치환문자열 + 뒤 문자열
	str_free(sep_str);
	return (*line);
}

char	*split_dup_quote(char *line, char c)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = find_first_charactor(line, c);
	end = find_last_charactor(line, c);
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	while(start < end + 1)
		str[i++] = line[start++];
	str[i] = '\0';
	return (str);
}

