/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:59:45 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/26 17:15:38 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/includes/ft_printf.h"

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
}	t_map;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*pointer;
	t_vector	*size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_length;
	int 		endian;
}	t_image;

int main(int argc, char **argv);
char **ft_create_matrix(char *string);

#endif
