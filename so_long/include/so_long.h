/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:23:10 by soo               #+#    #+#             */
/*   Updated: 2022/06/24 13:41:25 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../srcs/libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define SIZE			60

typedef struct s_map
{
	char	**array;
	int		width;
	int		height;
}	t_map;

typedef struct s_param
{
	int	x;
	int	y;
	int	move;
	int	exit[2];
	int	collect;
}	t_param;

typedef struct s_img
{
	void	*wall;
	void	*bg;
	void	*player;
	void	*exit;
	void	*collect;
}	t_img;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	struct s_map	map;
	struct s_param	param;
	struct s_img	img;
}	t_game;

//main
void	exit_player(t_game *g, int prev_x, int prev_y);
void	move_player(t_game *g, int prev_x, int prev_y);
int		mouse_press(t_game *game);
int		key_press(int keycode, t_game *game);

//load_map
int		cnt_newline(int fd);
void	split_map(t_map *map, int fd, int cnt_line);
t_game	*map_parsing(t_game *game, char *map_file);
void	check_map_error(t_game *game);

//check_map
void	check_map_player(t_param *param, int i, int j);
void	check_map_exit(t_param *param, int i, int j);
int		check_map_item(t_map map, t_param *param);
int		check_map_wall(t_map map);
int		check_map_length(t_map map);

//set_image
void	image_init(void *mlx, t_img *img);
void	put_image(t_game *g, int w, int h);
void	set_image(t_game *game);

#endif