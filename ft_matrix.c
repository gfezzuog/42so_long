/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:33:36 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 12:45:21 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**ft_create_matrix(char *string, t_map map)
{
	int		fd;
	char	*row;
	int		i;

	i = 0;
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

t_map	ft_matrix_malloc(t_map map)
{
	map.cols = 0;
	map.rows = 0;
	map.map = malloc(sizeof(char *) * map.height + 1);
	while (map.rows < map.height)
	{
		map.map[map.rows] = malloc(sizeof(char) * map.length + 1);
		map.rows++;
	}
	return (map);
}

t_map	ft_matrix_hendler(char **argv)
{
	t_map	map;
	int		fd;
	int		i;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	map.length = ft_strlengnl(argv[1]) - 1;
	map.height = ft_count_rows(argv[1]);
	map = ft_matrix_malloc(map);
	map.map = ft_create_matrix(argv[1], map);
	map = ft_findplayer(map);
	i = ft_mapchecker(map);
	if (i == 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	close(fd);
	return (map);
}
