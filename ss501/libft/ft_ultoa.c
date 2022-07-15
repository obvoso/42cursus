/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:15:20 by schoe             #+#    #+#             */
/*   Updated: 2022/05/16 12:57:44 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_size(size_t nb)
{
	size_t	size;

	size = 0;
	while (nb > 0 || size == 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void	ft_write(char *arr, size_t size, size_t nb)
{
	size_t	i;

	i = 0;
	arr[size + i] = '\0';
	while (size > 0)
	{
		arr[size + i - 1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
}

char	*ft_ultoa(size_t n)
{
	char	*arr;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_size(n);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == NULL)
		return (NULL);
	ft_write(arr, size, n);
	return (arr);
}
