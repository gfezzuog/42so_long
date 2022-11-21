/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:36:27 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 17:32:00 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveup(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->py - 1][map->px] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->py - 1][map->px] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->py - 1][map->px] == '1'
		|| (map->map[map->py - 1][map->px] == 'E' && map->opening == 0))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->py--;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.player.pointer, map->px * 64, map->py * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}

void	ft_movedown(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->py + 1][map->px] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->py + 1][map->px] == 'N')
		ft_freematrix(game->map);
		map->map[map->py][map->px] = '0';
	if (map->map[map->py + 1][map->px] == '1'
		|| (map->map[map->py + 1][map->px] == 'E' && map->opening == 0))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->py++;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.player.pointer, map->px * 64, map->py * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}

void	ft_moveleft(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->py][map->px - 1] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->py][map->px - 1] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->py][map->px - 1] == '1'
		|| (map->map[map->py][map->px - 1] == 'E' && map->opening == 0))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->px--;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.player.pointer, map->px * 64, map->py * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}

void	ft_moveright(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->py][map->px + 1] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->py][map->px + 1] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->py][map->px + 1] == '1'
		|| (map->map[map->py][map->px + 1] == 'E' && map->opening == 0))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->px++;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.player.pointer, map->px * 64, map->py * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}
