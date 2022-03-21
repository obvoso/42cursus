/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:32:34 by soo               #+#    #+#             */
/*   Updated: 2022/03/17 17:22:24 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_p;
	unsigned const char	*s2_p;

	s1_p = (unsigned const char *) s1;
	s2_p = (unsigned const char *) s2;
	while (*s1_p == *s2_p && --n)
	{
		++s1_p;
		++s2_p;
	}
	return (*s1_p - *s2_p);
}
