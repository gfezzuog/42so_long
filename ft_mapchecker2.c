/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:56:07 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/02 19:08:49 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rightlength(t_map map)
{
	map.cols = 0;
	map.rows = 0;
	while (map.cols < map.height)
	{
		while (map.map[map.cols][map.rows])
			map.rows++;
		if (map.rows != map.length)
			return (0);
		map.rows = 0;
		map.cols++;
	}
	return (1);
}

int	ft_rightheight(t_map map)
{
	map.cols = 0;
	while (map.map[map.cols])
		map.cols++;
	if (map.cols != map.height)
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
				&& map.map[map.cols][map.rows] != 'P')
				return (0);
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	return (1);
}