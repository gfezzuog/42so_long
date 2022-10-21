/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_max_min_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:43 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:43:45 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	ft_int_max_min_check(char *elem)
{
	if (ft_strlen(elem) > 11)
		return (1);
	if (ft_strlen(elem) == 10)
	{
		if (elem[0] > 50 || elem[1] > 49 || elem[2] > 52 || elem[3] > 55 \
		|| elem[4] > 52 || elem[5] > 56 || elem[6] > 51 || elem[7] > 54 \
		|| elem[8] > 52 || elem[9] > 55)
			return (1);
	}
	else if (ft_strlen(elem) == 11)
	{
		if (elem[0] != '-')
			return (1);
		if (elem[1] > 50 || elem[2] > 49 || elem[3] > 52 || elem[4] > 55 \
		|| elem[5] > 52 || elem[6] > 56 || elem[7] > 51 || elem[8] > 54 \
		|| elem[9] > 52 || elem[10] > 56)
			return (1);
	}
	return (0);
}
