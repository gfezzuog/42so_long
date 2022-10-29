/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:33:36 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/29 14:48:17 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_count_rows(char *string)
{
	int	rows;
	int	fd;

	fd = open(string, O_RDONLY);
	rows = 0;
	while (get_next_line(fd, 1))
		rows++;
	return (rows);
}

char	**ft_create_matrix(char *string)
{
	int		fd;
	char	*row;
	int		i;
	t_map	map;

	i = 0;
	map.length = 0;
	map.height = 0;
	fd = open(string, O_RDONLY);
	row = get_next_line(fd, 1);
	while (i < ft_count_rows(string))
	{
		map.map[i] = row;
		row = get_next_line(fd, 1);
		i++;
	}
	return (map.map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.length = 0;
	map.height = 0;
	printf("%s\n", argv[1]);
	if (argc != 2)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	map.map = ft_create_matrix(argv[1]);
	//ft_mapchecker(map);
	// while (map.map[map.height])
	// {
	// 	while (map.map[map.height][map.length])
	// 	{
	// 		printf("%c", map.map[map.height][map.length]);
	// 		map.length++;
	// 	}
	// 	map.length = 0;
	// 	map.height++;
	// }
	return (0);
}
