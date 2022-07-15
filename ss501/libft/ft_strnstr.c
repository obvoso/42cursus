/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:58:52 by schoe             #+#    #+#             */
/*   Updated: 2022/03/17 18:03:46 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	s;
	size_t	f;

	s = 0;
	if (substr[0] == '\0')
		return ((char *)str);
	while (str[s] && s < len)
	{
		f = 0;
		while (str[s + f] == substr[f] && (s + f) < len)
		{
			if (substr[f + 1] == '\0')
				return ((char *)&str[s]);
			f++;
		}
		s++;
	}
	return (NULL);
}
