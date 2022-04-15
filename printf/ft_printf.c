/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:46:04 by soo               #+#    #+#             */
/*   Updated: 2022/04/15 22:43:21 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	cnt;

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
			if (*str == '%')
			{
				write(1, "%", 1);
				++cnt;
			}
			else if (*str == 'd' || *str == 'i')
				cnt += print_dec_int(ap);
			else if (*str == 'c')
				cnt += print_char(ap);
			else if (*str == 's')
				cnt += print_str(ap);
			else if (*str == 'u')
				cnt += print_unsigned_int(ap);
			else if (*str == 'x' || *str == 'X')
			{
				if (*str == 'x')
					print_hex(ap, "0123456789abcdef");
				else
					print_hex(ap, "0123456789ABCDEF");
			}
			else if (*str == 'p')
				print_addr(ap);
			else
				return (-1);
			++str;
		}
	}
	va_end(ap);
	return (cnt);
}

int	main()
{
	char c = 'c';
	int cnt1 = 0;
	int cnt2 = 0;

	cnt1 = printf("test\n\ndec:%d\nint:%i\nchar:%c\nstr:%s\n\ntest2\n16진수x:%x\n16진수X:%X\nunsigined int:%u\naddress:%p\n\n", 999999999, 99999999, c, "abcde", 9999999, 9999999, 21, &c);
	cnt2 = ft_printf("test\n\ndec:%d\nint:%i\nchar:%c\nstr:%s\n\ntest2\n16진수x:%x\n16진수X:%X\nunsigined int:%u\naddress:%p\n\n", 999999999, 99999999, c, "abcde", 9999999, 9999999, 21, &c);
	
	//cnt1 = printf("%d\n%c\n", 123, c);
	//cnt2 = ft_printf("%d\n%c\n", 123, c);
	//cnt1 = printf("%", 1);
	// cnt1 = printf("%%\n");
	// cnt2 = ft_printf("%%\n");

	printf("cnt1:%d\ncnt2:%d\n", cnt1, cnt2);

}