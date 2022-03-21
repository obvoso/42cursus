/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:23:02 by soo               #+#    #+#             */
/*   Updated: 2022/03/20 21:55:57 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	cnt_str(char const *s, char c)
{
	unsigned int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s != c && *s)
				++s;
		}
		++s;
	}
	return (cnt);
}

char	*str_cpy(char const *start, char const *end)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(end - start + 1);
	if (!ret)
		return (NULL); 
	while (start < end)
		ret[i++] = *start++;
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char			**ret;
	const char		*start;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c && *s)
				++s;
			ret[i] = (char *)malloc(s - start + 1);
			ret[i] = str_cpy(start, s);
			++i;
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
