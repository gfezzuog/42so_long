/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:48:07 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/02 19:08:18 by gfezzuog         ###   ########.fr       */
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
	if (ft_firstpillar(map) == 1 && ft_lastpillar(map) == 1)
	{
		printf("pillars are closed\n");
		return (1);
	}
	else
	{
		printf("pillars are not closed\n");
		return (0);
	}
	if (ft_rightlength(map) == 1)
	{
		printf("length is right\n");
		return (1);
	}
	else
	{
		printf("length is not right\n");
		return (0);
	}
	if (ft_rightheight(map) == 1)
	{
		printf("height is right\n");
		return (1);
	}
	else
	{
		printf("height is not right\n");
		return (0);
	}
	if (ft_rightobj(map) == 1)
	{
		printf("objects are right\n");
		return (1);
	}
	else
	{
		printf("objects are not right\n");
		return (0);
	}
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