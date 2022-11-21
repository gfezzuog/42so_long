/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:43:42 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 14:01:05 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	find_exit(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	while (map->cols < map->height)
	{
		while (map->rows < map->length)
		{
			if (map->map[map->cols][map->rows] == 'E')
			{
				map->ex = map->rows;
				map->ey = map->cols;
			}
			map->rows++;
		}
		map->rows = 0;
		map->cols++;
	}
	return (*map);
}

int	count_collectibles(t_map map)
{
	int	collectibles;

	collectibles = 0;
	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'C')
				collectibles++;
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	return (collectibles);
}

void	check_opening(t_map *map, t_game *game)
{
	map->opening = 0;
	*map = find_exit(map);
	if (game->obj.fire > 2)
	{
		ft_createfloortoenemy(game->mlx, game->win, game->obj, game->map);
		game->obj.fire = 0;
	}
	if (count_collectibles(*map) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->obj.exit2.pointer, map->ex * 64, map->ey * 64);
		map->opening = 1;
	}
}
