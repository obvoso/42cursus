/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_str_utill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:15 by soo               #+#    #+#             */
/*   Updated: 2022/07/11 22:02:07 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "quote.h"
#include "env.h"
//!!널가드 추가

char	*arrange_str_cpy(char *ret, char *s1, char *s2, char *s3)
{
	int	i;
	
	//printf("0 : %s\n1 : %s\n2 : %s\n", s1, s2 ,s3);
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

char	*arrange_str(char **sep_str, char **line, int p_1, int p_2)
{
	char	**split_line;
	// int		back;
	int		tmp;
	
	split_line = (char **)malloc(sizeof(char *) * 3);
	split_line[0] = ft_strndup(*line, p_1);
	// if (find_first_c(split_line[0], ''))
	// printf("line : %s\n", *line);
	// printf("split_line[0] %d\n", ft_strlen(split_line[0]));
	// printf("sep_str[0] %s\n", sep_str[0]);
	// printf("치환 전  : %d\n", ft_strlen(sep_str[0]) + 1);
	// printf("line %d\n", ft_strlen(*line));
	// back = ft_strlen(split_line[0]) + ft_strlen(sep_str[0]) + 1; //치환 전 키값 + 1($)
	// printf("back %d\n", back);
	split_line[1] = ft_strdup(&line[0][p_2 + 1]);
	split_line[2] = NULL;
	printf("arrange : \n1%s;\n2%s;\n3%s;\n", split_line[0], sep_str[1], split_line[1]);
	free(*line);
	*line = (char *)malloc(ft_strlen(split_line[0]) + \
			ft_strlen(split_line[1]) + ft_strlen(sep_str[1]) + 1);
	*line = arrange_str_cpy(*line, split_line[0], sep_str[1], split_line[1]);
	// printf("ret line : %s\n", *line);
	str_free(split_line);
	return (*line);
}

int		find_end(char *line)
{
	int	dollar;
	int	space;
	int	quote;
	int	end;

	dollar = find_first_c(line, '$');
	space =  find_first_c(line, ' ');
	quote =  find_first_c(line, '\"');
	if ((!space || (quote < space)) && (!dollar || quote < dollar))
		return (quote);
	else if ((!quote || (dollar < quote)) && (!space || dollar < space))
		return (dollar);
	return (space);
}

char	*substitution_env(t_env *env, char **line, char *origin, int exit_code)
{
	char	**sep_str;
	int		dollar;
	int		end;
	int		tmp;

	dollar = find_first_c(*line, '$');
	tmp = find_first_c(&line[0][dollar], '\'');
	if (tmp && tmp < find_first_c(&line[0][dollar], '\"'))
	{
		tmp = find_first_c(&line[0][dollar], '\"') + dollar;
		dollar = find_first_c(&line[0][tmp], '$') + tmp;
	}
	end = find_end(&line[0][dollar + 1]) + dollar;
	sep_str = (char **)malloc(sizeof(char *) * 3);
	sep_str[0] = ft_strndup(&line[0][dollar + 1], end - dollar); // 치환할 키
	sep_str[1] = find_env(env, sep_str[0], exit_code); // 치환된 value
	if (!sep_str[1]) // "$유효하지 않은 value"일 때 치환하기 전 문자를 전달"
	{
		sep_str[1] = ft_strndup(&line[0][dollar], end - dollar + 1);
		find_exit_code(sep_str, exit_code);
	}
	sep_str[2] = NULL;
	arrange_str(sep_str, line, dollar, end); // 치환 문자 기준 앞 문자열 + 치환문자열 + 뒤 문자열
	str_free(sep_str);
	return (*line);
}

char	*split_dup_quote(char *origin, char **split, char c)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	// printf("origin : %s\n", origin);
	start = find_first_c(origin, c);
	end = find_first_c(&origin[start + 1], c) + start;
	while (start)
	{
		split[0] = ft_strndup(origin, start);
		split[1] = ft_strdup(&origin[end + 2]);
		str = ft_strndup(&origin[start], end - start + 2);
		start = find_first_c(origin, c);
		end = find_first_c(&origin[start + 1], c) + start;

	}
	// if (c == '\"')
		// printf("start : %d\nend : %d\n", start, end);
	// printf("str %s;\n", str);
	// printf("split %s;\n%s;\n", split[0], split[1]);
	return (str);
}

// char	*split_dup_quote(char *origin, char **split, char c)
// {
// 	char	*str;
// 	int		start;
// 	int		end;
// 	int		i;

// 	i = 0;
// 	// printf("origin : %s\n", origin);
// 	start = find_first_c(origin, c);
// 	end = find_last_c(origin, c);
// 	// if (c == '\"')
// 	// 	printf("start : %d\nend : %d\n", start, end);
// 	split[0] = ft_strndup(origin, start);
// 	split[1] = ft_strdup(&origin[end + 1]);
// 	str = ft_strndup(&origin[start], end - start + 1);
// 	printf("str %s\n", str);
// 	// printf("split %s\n%s\n", split[0], split[1]);
// 	return (str);
// }

