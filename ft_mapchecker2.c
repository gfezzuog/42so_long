/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:56:07 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 17:21:06 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_right_quantity(t_map map)
{
	map.cols = 0;
	map.rows = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'C')
				map.c++;
			if (map.map[map.cols][map.rows] == 'E')
				map.e++;
			if (map.map[map.cols][map.rows] == 'P')
				map.p++;
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	if (map.c == 0 || map.e == 0 || map.p == 0)
		return (0);
	return (1);
}

int	ft_rightobj(t_map map)
{
	map.cols = 0;
	map.rows = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] != '1'
				&& map.map[map.cols][map.rows] != '0'
				&& map.map[map.cols][map.rows] != 'C'
				&& map.map[map.cols][map.rows] != 'E'
				&& map.map[map.cols][map.rows] != 'P'
				&& map.map[map.cols][map.rows] != 'N')
				return (0);
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	return (1);
}
