/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:42:19 by soo               #+#    #+#             */
/*   Updated: 2022/06/16 21:31:36 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_argv(char **av, int ac)
{
	if (ac < 5)
	{
		ft_putstr_fd("Format Error\n", 2);
		return (1);
	}
	if (check_slash_dot(av))
	{
		ft_putstr_fd("Format Error\n", 2);
		return (1);
	}
	if (check_char(av))
	{
		ft_putstr_fd("Format Error\n", 2);
		return (1);
	}
	return (0);
}

int	check_char(char **av)
{
	int		i;
	char	c;

	i = 0;
	while (av[++i])
	{
		c = av[i][0];
		if (!ft_isalnum(((int)c)) && c != '/' && c != '.')
		{
			if (ft_strncmp(av[1], "here_doc", 8) && i != 2)
			{
				ft_putstr_fd("Format Error\n", 2);
				return (1);
			}
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
		if (ft_strncmp(av[1], "here_doc", 8) \
			&& (ft_strlen(av[i]) < 3 && c == '.'))
			return (1);
		if (c == '/' && ft_strlen(av[i]) == 1)
			return (1);
		if (c == '/' && !ft_isalnum(av[i][1]))
			return (1);
	}
	return (0);
}
