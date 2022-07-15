/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:37:21 by schoe             #+#    #+#             */
/*   Updated: 2022/05/16 12:58:11 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_s(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_p(void *p)
{
	char	*str;
	int		i;
	size_t	addr;

	addr = (size_t)p;
	str = ft_u_convert_base(ft_ultoa(addr), "0123456789", "0123456789abcdef");
	if (str == NULL)
		return (-1);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str) + 2;
	free(str);
	return (i);
}

int	ft_di(int d)
{
	char	*str;
	int		i;

	str = ft_itoa(d);
	if (str == NULL)
		return (-1);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_xu(unsigned int ud, char type)
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
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}
