/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:37:58 by soo               #+#    #+#             */
/*   Updated: 2022/06/24 13:28:17 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_player(t_param *param, int i, int j)
{
	if (!param->x && !param->y)
	{
		param->x = j;
		param->y = i;
	}
	else
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(1);
	}
}

void	check_map_exit(t_param *param, int i, int j)
{
	if (!param->exit[0])
	{
		param->exit[0] = i;
		param->exit[1] = j;
	}
	else
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(1);
	}
}

int	check_map_item(t_map map, t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (map.array[i])
	{
		j = 0;
		while (map.array[i][j])
		{
			if (map.array[i][j] == 'P')
				check_map_player(param, i, j);
			else if (map.array[i][j] == 'E')
				check_map_exit(param, i, j);
			else if (map.array[i][j] == 'C')
				++param->collect;
			else if ((map.array[i][j] == '0') || (map.array[i][j] == '1'))
				;
			else
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_map_wall(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.array[i] && i < map.height)
	{
		j = 0;
		while (map.array[i][j] && j < map.width)
		{
			if ((i == 0 || i == map.height - 1) && map.array[i][j] != '1')
				return (1);
			else
				if ((j == 0 || j == map.width - 1) && map.array[i][j] != '1')
					return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_map_length(t_map map)
{
	int	i;
	int	line_width;

	i = 0;
	while (i < map.height)
	{
		line_width = ft_strlen(map.array[i]);
		if (line_width != map.width)
			return (1);
		++i;
	}
	return (0);
}
