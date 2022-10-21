/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:32 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:43:34 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*stack;
	size_t	dimension;

	dimension = count * size;
	stack = (char *) malloc(sizeof(char) * dimension);
	if (!stack)
		return (0);
	else
		ft_bzero(stack, dimension);
	return (stack);
}
