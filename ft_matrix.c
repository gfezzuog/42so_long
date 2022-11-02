/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:33:36 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/29 16:35:46 by gfezzuog         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	fd = 0;
	map.cols = 0;
	map.rows = 0;
	if (argc != 2)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	map.length = ft_strlengnl(argv[1]) - 1;
	map.height = ft_count_rows(argv[1]);
	printf("length: %d\nheight: %d\n", map.length, map.height);
	map.map = malloc(sizeof(char *) * map.height + 1);
	while (map.rows < map.height)
	{
		map.map[map.rows] = malloc(sizeof(char) * map.length + 1);
		map.rows++;
	}
	map.rows = 0;
	map.map = ft_create_matrix(argv[1], map);
	ft_mapchecker(map);
	while (map.rows < ft_count_rows(argv[1]))
	{
		while (map.map[map.rows][map.cols])
		{
			printf("%c", map.map[map.rows][map.cols]);
			map.cols++;
		}
		map.cols = 0;
		map.rows++;
	}
	printf("\n");
	close(fd);
	return (0);
}
