/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countinglen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:05:03 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 16:49:54 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlengnl(char *string)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(string, O_RDONLY);
	line = get_next_line(fd, 1);
	i = ft_strlen(line);
	free(line);
	printf("srlen%d\n", i);
	close (fd);
	return (i);
}

int	ft_count_rows(char *string)
{
	int		rows;
	int		fd;
	char	*line;

	fd = open(string, O_RDONLY);
	rows = 0;
	line = get_next_line(fd, 1);
	while (line != NULL)
	{
		rows++;
		free(line);
		line = get_next_line(fd, 1);
	}
	free(line);
	close (fd);
	printf("rows%d\n", rows);
	return (rows);
}
