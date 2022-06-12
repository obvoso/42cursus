/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:42:19 by soo               #+#    #+#             */
/*   Updated: 2022/06/12 21:13:25 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_arg(int ac, char **av)
{
	int		i;
	char	c;

	i = 0;
	if (ac != 5)
	{
		ft_putstr_fd("Format Error : \n", 2);
		return (1);
	}
	if (check_slash_dot(av))
	{
		ft_putstr_fd("Format Error : \n", 2);
		return (1);
	}
	while (av[++i])
	{
		c = av[i][0];
		if (!ft_isalnum(((int)c)) && c != '/' && c != '.')
		{
			ft_putstr_fd("Format Error : \n", 2);
			return (1);
		}
	}
	return (0);
}

int	check_slash_dot(char **av)
{
	int		i;
	char	c;

	i = 0;
	while (av[++i])
	{
		c = av[i][0];
		if ((ft_strlen(av[i]) < 3 && c == '.'))
			return (1);
		if ((c == '/' && !ft_isalnum(av[i][1])) || ft_strlen(av[i]) == 1)
			return (1);
	}
	return (0);
}
