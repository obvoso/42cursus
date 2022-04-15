#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	cnt_digit(size_t n, int len);
char	*ft_itoa(long long nb);
int	ft_putstr(char *str);
char	*convert_hex(size_t n, char *hex_base);
int	print_char(va_list ap);
int	print_dec_int(va_list ap);
int	print_str(va_list ap);
int	print_unsigned_int(va_list ap);
int	print_hex(va_list ap, char *hex_base);
int	print_addr(va_list ap);


#endif