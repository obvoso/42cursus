/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:33:29 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 15:09:42 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = 0;
	if (dest_len < dstsize)
	{
		while (src[src_len] && dest_len + src_len + 1 < dstsize)
		{
			dst[dest_len + src_len] = src[src_len];
			++src_len;
		}
		dst[dest_len + src_len] = '\0';
		return (ft_strlen(src) + dest_len);
	}
	return (ft_strlen(src) + dstsize);
}
