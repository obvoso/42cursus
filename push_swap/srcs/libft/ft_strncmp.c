/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:41:01 by soo               #+#    #+#             */
/*   Updated: 2022/05/28 22:36:37 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*s1_p;
	unsigned const char	*s2_p;

	s1_p = (unsigned const char *)s1;
	s2_p = (unsigned const char *)s2;
	if (n < 1)
		return (0);
	while (--n && *s1_p == *s2_p && *s1_p && *s2_p)
	{
		++s1_p;
		++s2_p;
	}
	return (*s1_p - *s2_p);
}
