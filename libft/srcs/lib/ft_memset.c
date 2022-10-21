/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:45:53 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:45:54 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	l;
	char	*k;

	k = str;
	l = c;
	while (len--)
	{
		*k++ = l;
	}
	return (str);
}
