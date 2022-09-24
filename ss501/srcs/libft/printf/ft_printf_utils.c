/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:46:19 by soo               #+#    #+#             */
/*   Updated: 2022/06/07 19:36:54 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnt_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		write(1, str++, 1);
		++cnt;
	}
	return (cnt);
}

int	pf_cnt_digit(size_t nb, int len)
{
	int	digit;

	digit = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		++digit;
		nb /= len;
	}
	return (digit);
}

char	*lltoa(long long nb)
{
	char		*ret;
	int			digit;

	digit = 1;
	if (nb < 0)
		digit += pf_cnt_digit((size_t)(nb * -1), 10);
	else
		digit = pf_cnt_digit((size_t)nb, 10);
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

char	*convert_hex(size_t n, char *hex_base)
{
	char	*ret;
	int		len;

	len = pf_cnt_digit(n, 16);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		ret[--len] = hex_base[n % 16];
		n /= 16;
	}
	return (ret);
}

int	print_hex(va_list ap, char *hex_base)
{
	char			*rst;
	int				cnt;
	unsigned int	ui;

	cnt = 0;
	ui = va_arg(ap, unsigned int);
	rst = convert_hex(ui, hex_base);
	if (!rst)
		return (-1);
	cnt = cnt_putstr(rst);
	free(rst);
	rst = NULL;
	return (cnt);
}
