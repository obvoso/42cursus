/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_str_utill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:15 by soo               #+#    #+#             */
/*   Updated: 2022/07/07 22:16:17 by soo              ###   ########.fr       */
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

char	*arrange_str(char **sep_str, char *line, int front, int back)
{
	int		i;
	char	**split_line;
	char	*ret;

	split_line = (char **)malloc(sizeof(char *) * 3);
	split_line[2] = NULL;
	i = 0;
	split_line[0] = ft_strndup(line, front);
	split_line[1] = ft_strdup(&line[back]);
	printf("%s\n%s\n", split_line[0], split_line[1]);
	ret = (char *)malloc(ft_strlen(split_line[0]) + \
			ft_strlen(split_line[1]) + ft_strlen(sep_str[1]) + 1);
	ret = arrange_str_cpy(ret, split_line[0], sep_str[1], split_line[1]);
	str_free(split_line);
	return (ret);
}

char	*substitution_env(t_env *env, char *str, char *origin, int exit_code)
{
	char	**sep_str;
	int		doller;
	int		end;
	int		i;

	sep_str = (char **)malloc(sizeof(char *) * 3);
	sep_str[2] = NULL;
	
	doller = find_first_charactor(str, '$');
	end = find_first_charactor(&str[doller], '\"');
	sep_str[0] = (char *)malloc(end - doller + 1);
	i = 0;
	while(++doller > end)
		sep_str[0][i++] = str[doller]; // HOME 일캐 복사 $뺌
	sep_str[0][i] = '\0';
	sep_str[1] = find_env(env, sep_str[0], exit_code);
	free(str);
	str = arrange_str(sep_str, origin, doller - 1, end);
	str_free(sep_str);
	return (str);
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
	printf("%d %d\n", start, end);
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	while(start < end + 1)
		str[i++] = line[start++];
	str[i] = '\0';
	return (str);
}
