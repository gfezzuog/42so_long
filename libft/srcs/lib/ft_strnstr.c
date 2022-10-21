/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:47:20 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:47:21 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	ch;
	size_t	i;

	ch = *needle;
	i = ft_strlen(needle);
	if (ch == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && len-- >= i)
	{
		if ((ch == *haystack) && (ft_memcmp(haystack, needle, i) == 0))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
