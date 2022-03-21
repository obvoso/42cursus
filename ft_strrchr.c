/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:37:34 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 15:10:19 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p)
		++p;
	if (*p == c)
		return ((char *)p);
	--p;
	while (s <= p)
	{
		if (*p == c)
			return ((char *)p);
		--p;
	}
	return (NULL);
}
