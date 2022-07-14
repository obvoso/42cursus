/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:43:22 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 17:35:13 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *)haystack) < ft_strlen((char *)needle))
		return (NULL);
	if ((*needle == 0 && !len) || (!ft_strncmp(haystack, needle, len) && len))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
			++j;
		if (!needle[j])
			return ((char *)&haystack[i]);
		++i;
	}
	return (NULL);
}
