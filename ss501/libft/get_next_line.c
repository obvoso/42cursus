/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:46:38 by schoe             #+#    #+#             */
/*   Updated: 2022/06/16 21:58:26 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_get(ssize_t deep, int fd)
{
	char	*str;
	char	c;
	ssize_t	n;

	c = 0;
	n = read(fd, &c, 1);
	if (n < 0 || (n == 0 && deep == 0))
		return (NULL);
	if (c == '\n')
	{
		str = (char *)malloc(deep + 2);
		str[deep + 1] = '\0';
	}
	else if (c == '\0')
		str = (char *)malloc(deep + 1);
	else
		str = ft_get(deep + 1, fd);
	if (str)
		str[deep] = c;
	return (str);
}

char	*get_next_line(int fd)
{
	return (ft_get(0, fd));
}
