/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countinglen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:05:03 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/02 19:11:22 by gfezzuog         ###   ########.fr       */
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
	close (fd);
	return (i);
}

int	ft_count_rows(char *string)
{
	int	rows;
	int	fd;

	fd = open(string, O_RDONLY);
	rows = 0;
	while (get_next_line(fd, 1) != NULL)
		rows++;
	close (fd);
	return (rows);
}