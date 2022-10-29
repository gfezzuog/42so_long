/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:48:07 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/29 14:43:37 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_firstrow(t_map map)
{
	map.length = 0;
	map.height = 0;
	while (map.map[map.height][map.length] != '\n'
			&& map.map[map.height][map.length] != '\0')
	{
		if (map.map[map.height][map.length] != '1')
			return (0);
		map.length++;
	}
	return (1);
}

int	ft_lastrow(t_map map)
{
	map.length = 0;
	map.height = ft_pillarlen(map.map);
	while (map.map[map.height][map.length] != '\n'
			&& map.map[map.height][map.length] != '\0')
	{
		if (map.map[map.height][map.length] != '1')
			return (0);
		map.length++;
	}
	return (1);
}

int	ft_firstpillar(t_map map)
{
	map.length = 0;
	map.height = 0;
	while (map.height <= ft_pillarlen(map.map))
	{
		if (map.map[map.height][map.length] != '1')
			return (0);
		map.height++;
	}
	return (1);
}

int	ft_lastpillar(t_map map)
{
	map.length = ft_rowlen(map.map);
	map.height = 0;
	printf("%i\n", map.length);
	while (map.height <= ft_pillarlen(map.map))
	{
		if (map.map[map.height][map.length] != '1')
			return (0);
		map.height++;
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
	return (1);
}




//int	ft_checkrows(t_map map)
// {
// 	map.length = 0;
// 	map.height = 0;
// 	while (map.map[map.height][map.length] != '\n'
// 			&& map.map[map.height][map.length]
// 			&& map.map[map.height])
// 	{
// 		if (map.map[map.height][map.length] == '1')
// 			map.length++;
// 		else
// 			return (0);
// 	}
// 	map.length = ft_strlen(map.map[0]);
// 	map.height = ft_pillarlen(map.map);
// 	while (map.length > 0)
// 	{
// 		if (map.map[map.height][map.length] == '1')
// 			map.length--;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// int	ft_checkpillar(t_map map)
// {
// 	map.length = 0;
// 	map.height = 0;
// 	while (map.map[map.height][map.length] != '\n'
// 			&& map.map[map.height][map.length]
// 			&& map.map[map.height])
// 	{
// 		if (map.map[map.height][map.length] == '1')
// 			map.height++;
// 		else
// 			return (0);
// 	}
// 	map.height = ft_pillarlen(map.map);
// 	map.length = ft_strlen(map.map[0]) - 1;
// 	while (map.height > 0)
// 	{
// 		if (map.map[map.height][map.length] == '1')
// 			map.height--;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }