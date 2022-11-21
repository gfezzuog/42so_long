/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:00:26 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 14:05:56 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printingfloor(void *mlx, void *win, t_obj obj, t_map map)
{
	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] != '1'
				&& map.map[map.cols][map.rows] != 'N')
				mlx_put_image_to_window(mlx, win, obj.floor.pointer,
					map.rows * 64, map.cols * 64);
			map.rows++;
		}
		map.cols++;
		map.rows = 0;
	}
}

void	ft_createfloortoenemy(void *mlx, void *win, t_obj obj, t_map map)
{
	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'N')
			{
				mlx_put_image_to_window(mlx, win, obj.floor.pointer,
					map.rows * 64, map.cols * 64);
				mlx_put_image_to_window(mlx, win, obj.fire1.pointer,
					map.rows * 64, map.cols * 64);
			}
			map.rows++;
		}
		map.cols++;
		map.rows = 0;
		obj.fire = 0;
	}
}

void	ft_create_enemy(void *mlx, void *win, t_obj obj, t_map map)
{
	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'N' && obj.fire == 0)
				mlx_put_image_to_window(mlx, win, obj.fire1.pointer,
					map.rows * 64, map.cols * 64);
			else if (map.map[map.cols][map.rows] == 'N' && obj.fire == 1)
				mlx_put_image_to_window(mlx, win, obj.fire2.pointer,
					map.rows * 64, map.cols * 64);
			else if (map.map[map.cols][map.rows] == 'N' && obj.fire == 2)
				mlx_put_image_to_window(mlx, win, obj.fire3.pointer,
					map.rows * 64, map.cols * 64);
			map.rows++;
		}
		map.cols++;
		map.rows = 0;
	}
}

void	ft_printmap(void *mlx, void *win, t_obj obj, t_map map)
{
	map.rows = 0;
	map.cols = 0;
	ft_printingfloor(mlx, win, obj, map);
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'P')
				mlx_put_image_to_window(mlx, win, obj.player.pointer,
					map.rows * 64, map.cols * 64);
			if (map.map[map.cols][map.rows] == '1')
				mlx_put_image_to_window(mlx, win, obj.wall.pointer,
					map.rows * 64, map.cols * 64);
			if (map.map[map.cols][map.rows] == 'C')
				mlx_put_image_to_window(mlx, win, obj.collect.pointer,
					map.rows * 64, map.cols * 64);
			if (map.map[map.cols][map.rows] == 'E')
				mlx_put_image_to_window(mlx, win, obj.exit1.pointer,
					map.rows * 64, map.cols * 64);
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	ft_create_enemy(mlx, win, obj, map);
}
