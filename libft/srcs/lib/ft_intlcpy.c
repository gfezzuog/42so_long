/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:50 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:43:52 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	*ft_intlcpy(int *dst, const int *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	dst = malloc (sizeof(int) * (dstsize + 1));
	while (*src && i < dstsize)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
