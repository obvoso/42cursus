/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:46:04 by soo               #+#    #+#             */
/*   Updated: 2022/04/17 13:28:46 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	div_format(char format, va_list ap)
{
	if (format == '%')
		return (write(1, "%", 1));
	if (format == 'd' || format == 'i')
		return (print_dec_int(ap));
	if (format == 'c')
		return (print_char(ap));
	if (format == 's')
		return (print_str(ap));
	if (format == 'u')
		return (print_unsigned_int(ap));
	if (format == 'x')
		return (print_hex(ap, "0123456789abcdef"));
	if (format == 'X')
		return (print_hex(ap, "0123456789ABCDEF"));
	if (format == 'p')
		return (print_addr(ap));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		cnt_tmp;

	cnt = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str++, 1);
			++cnt;
		}
		else
		{
			++str;
			cnt_tmp = div_format(*str, ap);
			if (cnt_tmp == -1)
				return (-1);
			cnt += cnt_tmp;
			++str;
		}
	}
	va_end(ap);
	return (cnt);
}
