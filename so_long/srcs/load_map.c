/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:35:44 by soo               #+#    #+#             */
/*   Updated: 2022/06/24 13:43:09 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cnt_newline(int fd)
{
	int		buf_size;
	int		cnt;
	char	buf[1];

	cnt = 0;
	buf_size = 1;
	while (buf_size > 0)
	{
		buf_size = read(fd, buf, 1);
		if (!buf_size)
			++cnt;
		if (*buf == '\n')
			++cnt;
	}
	return (cnt);
}

void	split_map(t_map *map, int fd, int cnt_line)
{
	int	i;
	int	last_idx;

	i = 0;
	map->array = (char **)malloc(sizeof(char *) * cnt_line + 1);
	while (i < cnt_line)
	{
		map->array[i] = get_next_line(fd);
		if (!map->array[i] || map->array[i][0] == '\n')
		{
			ft_putstr_fd("Error\nMap Error\n", 2);
			exit(1);
		}
		last_idx = ft_strlen(map->array[i]) - 1;
		if (map->array[i][last_idx] == '\n')
			map->array[i][last_idx] = '\0';
		++i;
	}
	map->array[i] = NULL;
	map->height = i;
	map->width = last_idx + 1;
}

t_game	*map_parsing(t_game *game, char *map_file)
{
	int	fd;
	int	cnt_line;
	int	idx;

	idx = ft_strlen(map_file) - 4;
	if (ft_strncmp(&map_file[idx], ".ber", 4))
	{
		ft_putstr_fd("Error\nARG Error\n", 2);
		exit(1);
	}
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		printf("%s: %s\n", strerror(errno), map_file);
		exit(1);
	}
	cnt_line = cnt_newline(fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	split_map(&game->map, fd, cnt_line);
	close(fd);
	check_map_error(game);
	return (game);
}

void	check_map_error(t_game *game)
{
	if (check_map_length(game->map))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(1);
	}
	if (check_map_wall(game->map))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(1);
	}
	if (check_map_item(game->map, &game->param))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(1);
	}
	if ((!game->param.x && !game->param.y) || !game->param.exit[0] \
		|| game->param.collect == 0)
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(1);
	}
}
