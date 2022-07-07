/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:10:01 by soo               #+#    #+#             */
/*   Updated: 2022/07/07 22:06:34 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len + 1);
	return (ret);
}

char	*ft_strndup(const char *s1, size_t size)
{
	char	*ret;

	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, size + 1);
	return (ret);
}