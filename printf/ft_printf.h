/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:49:38 by soo               #+#    #+#             */
/*   Updated: 2022/04/18 17:08:24 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		div_format(char format, va_list ap);
int		cnt_digit(size_t n, int len);
char	*ltoa(long long nb);
int		cnt_putstr(char *str);
char	*convert_hex(size_t n, char *hex_base);
int		print_char(va_list ap);
int		print_dec_int(va_list ap);
int		print_str(va_list ap);
int		print_unsigned_int(va_list ap);
int		print_addr(va_list ap);
int		print_hex(va_list ap, char *hex_base);

#endif