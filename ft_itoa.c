/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:44:21 by soo               #+#    #+#             */
/*   Updated: 2022/03/15 22:46:27 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cnt_digit(long long n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
	{
		++digit;
		n *= -1;
	}
	while (n)
	{
		++digit;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			digit;
	long long	nb;

	nb = (long long)n;
	digit = cnt_digit(nb);
	ret = (char *)malloc(digit + 1);
	if (!ret)
		return (NULL);
	ret[digit] = '\0';
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		ret[0] = '0';
	while (nb)
	{
		ret[--digit] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}