/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:57:44 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/08 19:57:08 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	create_obj(void *mlx, char *path)
{
	t_image img;
	t_vector size;

	img.pointer = mlx_xpm_file_to_image(mlx, path, &size.x, &size.y);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.size = &size;
	return (img);
}

void	ft_printmap(t_map map, void *mlx, void *win)
{
	t_image	img;

	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		printf("CULO %d\n", map.cols);
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'P')
			{
				img = create_obj(mlx, "./obj/player.xpm");
				mlx_put_image_to_window(mlx, win, img.pointer, map.rows * 64, map.cols * 64);
			}
			if (map.map[map.cols][map.rows] == '0')
			{
				img = create_obj(mlx, "./obj/floor.xpm");
				mlx_put_image_to_window(mlx, win, img.pointer, map.rows * 64, map.cols * 64);
			}
			if (map.map[map.cols][map.rows] == '1')
			{
				img = create_obj(mlx, "./obj/wall.xpm");
				mlx_put_image_to_window(mlx, win, img.pointer, map.rows * 64, map.cols * 64);
			}
			if (map.map[map.cols][map.rows] == 'C')
			{
				img = create_obj(mlx, "./obj/collectible.xpm");
				mlx_put_image_to_window(mlx, win, img.pointer, map.rows * 64, map.cols * 64);
			}
			if (map.map[map.cols][map.rows] == 'E')
			{
				img = create_obj(mlx, "./obj/closedtrapdoor.xpm");
				mlx_put_image_to_window(mlx, win, img.pointer, map.rows * 64, map.cols * 64);
			}
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	void	*mlx;
	void	*win;
	if (argc != 2)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	map = ft_matrix_hendler(argv);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "so_long");
	ft_printmap(map, mlx, win);
	mlx_loop(mlx);
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
//     mlx_put_image_to_window(mlx, win, img.pointer, 0, 0);
//     mlx_loop(mlx);
// }
