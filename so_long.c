/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:57:44 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/26 17:14:02 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image create_player(void *mlx, char *path)
{
    t_image img;
    img.size->x = 64;
    img.size->y = 64;
    img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size->x, &img.size->y);
    img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_length, &img.endian);
    return (img);
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
