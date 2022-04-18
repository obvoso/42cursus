/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:56:48 by soo               #+#    #+#             */
/*   Updated: 2022/04/18 17:14:30 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec_int(va_list ap)
{
	int		cnt;
	int		n;
	char	*rst;

	n = va_arg(ap, int);
	rst = ltoa(n);
	if (!rst)
		return (-1);
	cnt = cnt_putstr(rst);
	free(rst);
	rst = NULL;
	return (cnt);
}

int	print_char(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_str(va_list ap)
{
	char	*rst;

	rst = va_arg(ap, char *);
	if (!rst)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (cnt_putstr(rst));
}

int	print_unsigned_int(va_list ap)
{
	unsigned int	ui;
	char			*rst;
	int				cnt;

	cnt = 0;
	ui = va_arg(ap, unsigned int);
	rst = ltoa(ui);
	if (!rst)
		return (-1);
	cnt = cnt_putstr(rst);
	free(rst);
	rst = NULL;
	return (cnt);
}

int	print_addr(va_list ap)
{
	unsigned long	addr;
	char			*rst;
	int				cnt;

	addr = (unsigned long)va_arg(ap, void *);
	rst = convert_hex(addr, "0123456789abcdef");
	if (!rst)
		return (-1);
	write(1, "0x", 2);
	cnt = cnt_putstr(rst) + 2;
	free (rst);
	rst = NULL;
	return (cnt);
}
