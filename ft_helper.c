/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:48:11 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/08 17:36:02 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(t_map map)
{
	int	collectibles;

	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'C')
				collectibles++;
			map.rows++;
		}
		map.rows = 0;
	}
	return (collectibles);
}
