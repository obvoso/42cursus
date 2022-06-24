/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:39:41 by soo               #+#    #+#             */
/*   Updated: 2022/06/24 13:41:25 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_player(t_game *g, int prev_x, int prev_y)
{
	if (g->map.array[g->param.y][g->param.x] == 'E')
	{
		if (!g->param.collect)
			exit(0);
		else
		{
			mlx_put_image_to_window(g->mlx, g->win, g->img.player, \
									g->param.x * SIZE, g->param.y * SIZE);
			mlx_put_image_to_window(g->mlx, g->win, g->img.bg, \
									prev_x * SIZE, prev_y * SIZE);
		}
	}
	if (g->map.array[prev_y][prev_x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, \
								prev_x * SIZE, prev_y * SIZE);
}

void	move_player(t_game *g, int prev_x, int prev_y)
{
	if (g->map.array[g->param.y][g->param.x] == '1')
	{
		g->param.x = prev_x;
		g->param.y = prev_y;
		return ;
	}
	if (g->map.array[g->param.y][g->param.x] == '0' \
		|| g->map.array[g->param.y][g->param.x] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, \
								g->param.x * SIZE, g->param.y * SIZE);
		mlx_put_image_to_window(g->mlx, g->win, g->img.bg, \
								prev_x * SIZE, prev_y * SIZE);
		if (g->map.array[g->param.y][g->param.x] == 'C')
		{
			g->map.array[g->param.y][g->param.x] = '0';
			g->param.collect -= 1;
		}
	}
	exit_player(g, prev_x, prev_y);
	g->param.move += 1;
	printf("move_count : %d\n", g->param.move);
}

int	mouse_press(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.bg);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.collect);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->param.x;
	prev_y = game->param.y;
	if (keycode == KEY_W)
		game->param.y--;
	else if (keycode == KEY_S)
		game->param.y++;
	else if (keycode == KEY_A)
		game->param.x--;
	else if (keycode == KEY_D)
		game->param.x++;
	else if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	move_player(game, prev_x, prev_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nARG Error\n", 2);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	map_parsing(&game, argv[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * SIZE, \
							game.map.height * SIZE, "so_long");
	image_init(game.mlx, &game.img);
	set_image(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &mouse_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
