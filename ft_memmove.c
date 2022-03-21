/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:09:03 by soo               #+#    #+#             */
/*   Updated: 2022/03/17 17:57:16 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	dest_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	if (dest_p < src_p)
		while (len--)
			*dest_p++ = *src_p++;
	else if (dest_p > src_p)
		while (len--)
		dest_p[len] = src_p[len];
	return (dst);
}
