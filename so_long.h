/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:59:45 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/21 17:01:08 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"

typedef struct s_vector
{
    int x;
    int y;
}               t_vector;

typedef struct s_image
{
    void    *pointer;
    t_vector    *size;
    char    *pixels;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}            t_image;

#endif
