/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:04:05 by soo               #+#    #+#             */
/*   Updated: 2022/03/21 17:43:58 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_recur(long long nb, int fd)
{
	if (nb > 10)
		putnbr_recur(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	putnbr_recur(nb, fd);
}
