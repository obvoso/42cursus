/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:56:00 by schoe             #+#    #+#             */
/*   Updated: 2022/03/17 18:00:32 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d_o;
	size_t	d;

	d = 0;
	s = 0;
	d_o = 0;
	while (dst[d])
	{
		d++;
		d_o++;
	}
	while (src[s] && d_o + s + 1 < size)
	{
		dst[d_o + s] = src[s];
		s++;
	}
	dst[d_o + s] = '\0';
	while (src[s])
		s++;
	if (d_o > size)
		return (s + size);
	else
		return (d_o + s);
}
