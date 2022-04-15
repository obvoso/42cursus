/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:56:48 by soo               #+#    #+#             */
/*   Updated: 2022/04/15 22:45:41 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec_int(va_list ap)
{
	int	cnt;
	int		n;
	char	*rst;

	n = va_arg(ap, int);
	rst = ft_itoa(n);
	if (!rst)
		return (-1);
	cnt = ft_putstr(rst);
	free(rst);
	rst = NULL;
	return (cnt);
}

int	print_char(va_list ap)
{
	char	c;
	
	c = (char)va_arg(ap, int);
	if (c)
	{
		write(1, &c, 1);
		return (1);
	}
	return (-1);
}

int	print_str(va_list ap)
{
	char	*rst;

	rst = va_arg(ap, char *);
	if (!rst)
	{
		write( 1, "(null)", 6);
		return (6);
	}
	return (ft_putstr(rst));
}

int	print_unsigned_int(va_list ap)
{
	unsigned int	ui;
	char *			rst;
	int				cnt;

	cnt = 0;
	ui = va_arg(ap, unsigned int);
	rst = ft_itoa(ui);
	if (!rst)
		return (-1);
	cnt = ft_putstr(rst);
	free(rst);
	rst = NULL;
	return (cnt);
}

int	print_hex(va_list ap, char *hex_base)
{
	unsigned int	ui;
	char			*rst;
	int				cnt;

	cnt = 0;
	ui = va_arg(ap, unsigned int);
	rst = convert_hex(ui, hex_base);
	if (!rst)
		return (-1);
	cnt = ft_putstr(rst);
	free(rst);
	rst = NULL;
	return (cnt);
}

int	print_addr(va_list ap)
{
	size_t	addr;
	char	*rst;

	addr = (size_t)va_arg(ap, void *);
	rst = convert_hex(addr, "0123456789abcdef");
	if (!rst)
		return (-1);
	write(1, "0x", 2);
	return (ft_putstr(rst) + 2);
}