/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:57:44 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:23 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	create_obj(void *mlx, char *path)
{
	t_image		img;
	t_vector	size;

	img.pointer = mlx_xpm_file_to_image(mlx, path, &size.x, &size.y);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.size = &size;
	return (img);
}

t_obj	ft_chargetexture(void *mlx)
{
	t_obj	obj;

	printf("Loading textures...\n");
	obj.floor = create_obj(mlx, "./obj/floor.xpm");
	printf("Floor loaded\n");
	obj.wall = create_obj(mlx, "./obj/wall.xpm");
	printf("Wall loaded\n");
	obj.collect = create_obj(mlx, "./obj/collectible.xpm");
	printf("Collectable loaded\n");
	obj.exit1 = create_obj(mlx, "./obj/closedtrapdoor.xpm");
	printf("Closed trapdoor loaded\n");
	obj.exit2 = create_obj(mlx, "./obj/opentrapdoor.xpm");
	printf("Open trapdoor loaded\n");
	obj.player = create_obj(mlx, "./obj/player.xpm");
	printf("Player loaded\n");
	obj.fire1 = create_obj(mlx, "./obj/firstfire.xpm");
	printf("Fire1 loaded\n");
	obj.fire2 = create_obj(mlx, "./obj/secondfire.xpm");
	printf("Fire2 loaded\n");
	obj.fire3 = create_obj(mlx, "./obj/thirdfire.xpm");
	printf("Fire3 loaded\n");
	return (obj);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	game.map = ft_matrix_hendler(argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.length * 64,
			game.map.height * 64, "so_long");
	game.obj = ft_chargetexture(game.mlx);
	ft_printmap(game.mlx, game.win, game.obj, game.map);
	mlx_hook(game.win, 2, 1L << 0, ft_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
// int main(void)
// {
//     t_image  img;
//     void    *mlx;
//     void    *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 1920, 1080, "test");
//     img = create_player(mlx, "./player/player.xpm");
//     mlx_put_image_to_window(game->mlx, game->win, img.pointer, 0, 0);
//     mlx_loop(mlx);
// }
