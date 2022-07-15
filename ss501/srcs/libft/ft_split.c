/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:23:02 by soo               #+#    #+#             */
/*   Updated: 2022/07/05 17:35:05 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	cnt_str(char const *s, char c)
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
		else
			++s;
	}
	return (cnt);
}

static void	str_cpy(char *ret, char const *start, char const *end)
{
	while (start < end)
		*ret++ = *start++;
	 *ret = '\0';
}

static int	ctrl_split(char **ret, char const *s, char c)
{
	const char		*start;
	unsigned int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c && *s)
				++s;
			ret[i] = (char *)malloc(s - start + 1);
			if (!ret[i])
			{
				while (i > 0)
					free(ret[--i]);
				return (1);
			}
			str_cpy(ret[i++], start, s);
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1));
	if (!ret)
		return (NULL);
	if (ctrl_split(ret, s, c))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
