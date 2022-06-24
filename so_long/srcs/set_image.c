/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:31:09 by soo               #+#    #+#             */
/*   Updated: 2022/06/24 13:32:47 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(void *mlx, t_img *img)
{
	int	w;
	int	h;

	img->wall = mlx_xpm_file_to_image(mlx, "xpm_image/wall.xpm", &w, &h);
	img->bg = mlx_xpm_file_to_image(mlx, "xpm_image/bg.xpm", &w, &h);
	img->player = mlx_xpm_file_to_image(mlx, "xpm_image/player.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(mlx, "xpm_image/exit.xpm", &w, &h);
	img->collect = mlx_xpm_file_to_image(mlx, "xpm_image/collect.xpm", &w, &h);
}

void	put_image(t_game *g, int w, int h)
{
	int	w_size;
	int	h_size;

	w_size = w * SIZE;
	h_size = h * SIZE;
	if (g->map.array[h][w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w_size, h_size);
	else if (g->map.array[h][w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.collect, w_size, h_size);
	else if (g->map.array[h][w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w_size, h_size);
		g->map.array[h][w] = '0';
	}
	else if (g->map.array[h][w] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w_size, h_size);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.bg, w_size, h_size);
}

void	set_image(t_game *game)
{
	int	w;
	int	h;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			put_image(game, w, h);
			++w;
		}
		++h;
	}
}
