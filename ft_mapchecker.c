/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:48:07 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/03 03:27:57 by gfezzuog         ###   ########.fr       */
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
	if (ft_firstpillar(map) == 1 && ft_lastrow(map) == 1)
		printf("raws are closed\n");
	else
		printf("raws are not closed\n");
	if (ft_firstpillar(map) == 1 && ft_lastpillar(map) == 1)
		printf("pillars are closed\n");
	else
		printf("pillars are not closed\n");

	if (ft_rightobj(map) == 1)
		printf("objects are right\n");
	else
		printf("objects are not right\n");
	if (ft_right_quantity(map) == 1)
		printf("quantity is right\n");
	else
		printf("quantity is not right\n");
	return (1);
}

//int	ft_checkrows(t_map map)
// {
// 	map.length = 0;
// 	map.cols = 0;
// 	while (map.map[map.cols][map.length] != '\n'
// 			&& map.map[map.cols][map.length]
// 			&& map.map[map.cols])
// 	{
// 		if (map.map[map.cols][map.length] == '1')
// 			map.length++;
// 		else
// 			return (0);
// 	}
// 	map.length = ft_strlen(map.map[0]);
// 	map.cols = ft_pillarlen(map.map);
// 	while (map.length > 0)
// 	{
// 		if (map.map[map.cols][map.length] == '1')
// 			map.length--;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// int	ft_checkpillar(t_map map)
// {
// 	map.length = 0;
// 	map.cols = 0;
// 	while (map.map[map.cols][map.length] != '\n'
// 			&& map.map[map.cols][map.length]
// 			&& map.map[map.cols])
// 	{
// 		if (map.map[map.cols][map.length] == '1')
// 			map.cols++;
// 		else
// 			return (0);
// 	}
// 	map.cols = ft_pillarlen(map.map);
// 	map.length = ft_strlen(map.map[0]) - 1;
// 	while (map.cols > 0)
// 	{
// 		if (map.map[map.cols][map.length] == '1')
// 			map.cols--;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }