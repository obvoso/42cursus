/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:45:51 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 15:10:36 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		++start;
	while (start < end && ft_strrchr(set, s1[end - 1]))
		--end;
	ret = (char *)malloc(end - start + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &s1[start], end - start + 1);
	return (ret);
}
