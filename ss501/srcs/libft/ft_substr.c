/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:21:28 by soo               #+#    #+#             */
/*   Updated: 2022/03/22 22:30:51 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(&s[start]) > len)
		s_len = len;
	else
		s_len = ft_strlen(&s[start]);
	ret = (char *)malloc(s_len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start] && i < s_len && ft_strlen(s) > start)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
