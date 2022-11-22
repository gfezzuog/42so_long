/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:33 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/22 18:06:16 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freematrix(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
	exit(0);
}

void	ft_printopen(t_map *map, t_game game)
{
	map->cols = 0;
	map->rows = 0;
	while (map->cols < map->height)
	{
		while (map->rows < map->length)
		{
			if (map->map[map->cols][map->rows] == 'E')
				mlx_put_image_to_window(game.mlx, game.win,
					game.obj.exit2.pointer, map->rows * 64, map->cols * 64);
		}
	}
}

int	ft_keypress(int keycode, t_game *game)
{
	ft_writemoves(game);
	if (keycode == ESC)
	{
		ft_freematrix(game->map);
		exit(0);
	}
	if (keycode == KEY_UP || keycode == ARROW_UP)
		ft_moveup(&game->map, game);
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		ft_movedown(&game->map, game);
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
		ft_moveleft(&game->map, game);
	if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
		ft_moveright(&game->map, game);
	return (0);
}

t_map	ft_findplayer(t_map map)
{
	map.cols = 0;
	map.rows = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'P')
			{
				map.px = map.rows;
				map.py = map.cols;
			}
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	return (map);
}
