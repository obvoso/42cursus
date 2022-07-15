/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:48:22 by schoe             #+#    #+#             */
/*   Updated: 2022/03/14 18:45:04 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;
	size_t			i;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			temp_dst[len - 1] = temp_src[len - 1];
			len--;
		}
	}
	return (dst);
}
