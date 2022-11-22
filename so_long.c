/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:57:44 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/22 18:33:19 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	create_obj(void *mlx, char *path)
{
	t_image		img;
	t_vector	size;

	img.pointer = mlx_xpm_file_to_image(mlx, path, &size.x, &size.y);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.size = &size;
	return (img);
}

t_obj	ft_chargetexture(void *mlx)
{
	t_obj	obj;

	obj.floor = create_obj(mlx, "./obj/floor.xpm");
	obj.wall = create_obj(mlx, "./obj/wall.xpm");
	obj.collect = create_obj(mlx, "./obj/collectible.xpm");
	obj.exit1 = create_obj(mlx, "./obj/closedtrapdoor.xpm");
	obj.exit2 = create_obj(mlx, "./obj/opentrapdoor.xpm");
	obj.player = create_obj(mlx, "./obj/player.xpm");
	obj.fire1 = create_obj(mlx, "./obj/firstfire.xpm");
	obj.fire2 = create_obj(mlx, "./obj/secondfire.xpm");
	obj.fire3 = create_obj(mlx, "./obj/thirdfire.xpm");
	obj.fire = 0;
	return (obj);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	game.map = ft_matrix_hendler(argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.length * 64,
			game.map.height * 64, "so_long");
	game.obj = ft_chargetexture(game.mlx);
	game.moves = 0;
	ft_printmap(game.mlx, game.win, game.obj, game.map);
	mlx_string_put(game.mlx, game.win, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_hook(game.win, 2, 1L << 0, ft_keypress, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
