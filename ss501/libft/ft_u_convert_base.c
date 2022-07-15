/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_convert_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:06:45 by schoe             #+#    #+#             */
/*   Updated: 2022/05/16 12:58:23 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *base)
{
	int	k;
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (-1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' \
				|| base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (-1);
		k = i + 1;
		while (base[k])
		{
			if (base[i] == base[k])
				return (-1);
			k++;
		}
		i++;
	}
	return (i);
}

static int	base_find(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*new_base(size_t r, char *base_to)
{
	size_t	i;
	int		size;
	char	*str;

	i = r;
	size = 0;
	while (i > 0 || size == 0)
	{
		i /= check(base_to);
		size++;
	}
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base_to[r % check(base_to)];
		r /= check(base_to);
		size--;
	}
	return (str);
}

char	*ft_u_convert_base(char *nbr, char *base_from, char *base_to)
{
	size_t	i;
	size_t	r;

	r = 0;
	i = 0;
	if (check(base_from) < 0 || check(base_to) < 0)
		return (NULL);
	while (base_find(nbr[i], base_from) >= 0)
	{
		r = r * check(base_from) + base_find(nbr[i], base_from);
		i++;
	}
	free(nbr);
	return (new_base(r, base_to));
}
