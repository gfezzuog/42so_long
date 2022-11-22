/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createblack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:33 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/22 18:32:51 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_writemoves(t_game *game)
{
	char	*str;
	char	*str2;

	game->moves++;
	str2 = ft_itoa(game->moves - 1);
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00000000, str2);
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, str);
	free(str);
	free(str2);
}

int	ft_close(t_game *game)
{
	ft_freematrix(game->map);
	exit(0);
}
