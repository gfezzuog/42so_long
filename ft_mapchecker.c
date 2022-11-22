/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:48:07 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/22 18:04:59 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_firstrow(t_map map)
{
	map.rows = 0;
	map.cols = 0;
	while (map.rows < map.length)
	{
		if (map.map[map.cols][map.rows] != '1')
			return (0);
		map.rows++;
	}
	map.rows = 0;
	return (1);
}

int	ft_lastrow(t_map map)
{
	map.rows = 0;
	while (map.rows < map.length)
	{
		if (map.map[map.height - 1][map.rows] != '1')
			return (0);
		map.rows++;
	}
	map.rows = 0;
	return (1);
}

int	ft_firstpillar(t_map map)
{
	map.rows = 0;
	map.cols = 0;
	while (map.cols < map.height)
	{
		if (map.map[map.cols][map.rows] != '1')
			return (0);
		map.cols++;
	}
	return (1);
}

int	ft_lastpillar(t_map map)
{
	map.cols = 0;
	while (map.cols < map.height)
	{
		if (map.map[map.cols][map.length - 1] != '1')
			return (0);
		map.cols++;
	}
	return (1);
}

int	ft_mapchecker(t_map map)
{
	if (ft_firstpillar(map) == 0 || ft_lastrow(map) == 0)
		return (0);
	if (ft_firstpillar(map) == 0 || ft_lastpillar(map) == 0)
		return (0);
	if (ft_rightobj(map) == 0)
		return (0);
	if (ft_right_quantity(map) == 0)
		return (0);
	return (1);
}

// void	print(t_map map)
// {
// 	map.cols = 0;
// 	map.rows = 0;
// 	while (map.cols < map.height)
// 	{
// 		while (map.rows < map.length)
// 		{
// 			printf("%c", map.map[map.cols][map.rows]);
// 			map.rows++;
// 		}
// 		printf("\n");
// 		map.rows = 0;
// 		map.cols++;
// 	}
// }