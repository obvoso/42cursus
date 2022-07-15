/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:20:05 by schoe             #+#    #+#             */
/*   Updated: 2022/06/17 15:12:14 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_etype(va_list *ap, char type)
{
	if (type == 'c')
		return (ft_ec(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_es(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_ep(va_arg(*ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_edi(va_arg(*ap, int)));
	else if (type == 'x' || type == 'X' || type == 'u')
		return (ft_exu(va_arg(*ap, int), type));
	else if (type == '%')
		return (write(2, &type, 1));
	else
		return (-1);
}

int	ft_eprintf(const char *arg, ...)
{
	va_list	ap;
	int		count;
	int		check;

	check = 0;
	count = 0;
	va_start(ap, arg);
	while (*arg != '\0')
	{
		if (*arg == '%')
		{
			arg++;
			check = ft_etype(&ap, *arg);
			if (check == -1)
				break ;
			count += check;
		}
		else
			count += write(2, arg, 1);
		arg++;
	}
	va_end(ap);
	if (check == -1)
		return (-1);
	return (count);
}
