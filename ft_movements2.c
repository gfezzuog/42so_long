/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:36:27 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/16 18:23:41 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveup(t_map *map, t_game *game)
{
	if (map->map[map->py - 1][map->px] == '1' && move_helper(map, game))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->py--;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.player.pointer, map->px * 64, map->py * 64);
}

void	ft_movedown(t_map *map, t_game *game)
{
	if (map->map[map->py + 1][map->px] == '1' && move_helper(map, game))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->py++;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.player.pointer, map->px * 64, map->py * 64);
}

void	ft_moveleft(t_map *map, t_game *game)
{
	if (map->map[map->py][map->px - 1] == '1' && move_helper(map, game))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->px--;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.player.pointer, map->px * 64, map->py * 64);
}

void	ft_moveright(t_map *map, t_game *game)
{
	if (map->map[map->py][map->px + 1] == '1' && move_helper(map, game))
		return ;
	map->map[map->py][map->px] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer, map->px * 64, map->py * 64);
	map->px++;
	map->map[map->py][map->px] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->obj.player.pointer, map->px * 64, map->py * 64);
}
