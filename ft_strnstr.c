/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:43:22 by soo               #+#    #+#             */
/*   Updated: 2022/03/20 15:40:49 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const unsigned char	*str;
	const unsigned char	*find;

	if (ft_strlen((char *)haystack) < ft_strlen((char *)needle))
		return (NULL);
	if (*needle == '\0' || !ft_strncmp(haystack, needle, len))
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			str = (const unsigned char *)haystack;
			find = (const unsigned char *)needle;
			while (*find && *str == *find && len--)
			{
				++str;
				++find;
			}
			if (!*find)
				return ((char *)haystack);
		}
		 ++haystack;
	}
	return (NULL);
}
