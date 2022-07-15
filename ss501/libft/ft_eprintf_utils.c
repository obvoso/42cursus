/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:37:21 by schoe             #+#    #+#             */
/*   Updated: 2022/06/17 14:46:19 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_ec(char c)
{
	ft_putchar_fd(c, 2);
	return (1);
}

int	ft_es(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 2);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 2);
	return (ft_strlen(str));
}

int	ft_ep(void *p)
{
	char	*str;
	int		i;
	size_t	addr;

	addr = (size_t)p;
	str = ft_u_convert_base(ft_ultoa(addr), "0123456789", "0123456789abcdef");
	if (str == NULL)
		return (-1);
	ft_putchar_fd('0', 2);
	ft_putchar_fd('x', 2);
	ft_putstr_fd(str, 2);
	i = ft_strlen(str) + 2;
	free(str);
	return (i);
}

int	ft_edi(int d)
{
	char	*str;
	int		i;

	str = ft_itoa(d);
	if (str == NULL)
		return (-1);
	ft_putstr_fd(str, 2);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_exu(unsigned int ud, char type)
{
	char	*str;
	int		i;

	if (type == 'x')
		str = ft_u_convert_base(ft_ultoa(ud), "0123456789", "0123456789abcdef");
	else if (type == 'X')
		str = ft_u_convert_base(ft_ultoa(ud), "0123456789", "0123456789ABCDEF");
	else
		str = ft_ultoa(ud);
	if (str == NULL)
		return (-1);
	ft_putstr_fd(str, 2);
	i = ft_strlen(str);
	free(str);
	return (i);
}
