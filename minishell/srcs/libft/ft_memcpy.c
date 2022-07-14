/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:43:35 by soo               #+#    #+#             */
/*   Updated: 2022/03/17 17:56:16 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	if (n < 1 || (!dst && !src))
		return (dst);
	dest_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	while (n--)
		*dest_p++ = *src_p++;
	return (dst);
}
