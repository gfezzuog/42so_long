/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:45:32 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:45:33 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	ch;

	ch = (char) c;
	string = (char *) s;
	while (string != NULL && n--)
	{
		if (*string == ch)
			return (string);
		else
			string++;
	}
	return (NULL);
}
