/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createblack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:33 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/22 18:09:58 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_writemoves(t_game *game)
{
	char	*str;

	game->moves++;
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00000000,
		ft_itoa(game->moves - 1));
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, str);
	free(str);
}
