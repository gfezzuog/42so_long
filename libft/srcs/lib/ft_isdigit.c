/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:44:10 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:44:12 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"
#include	"../../includes/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (0);
	else
		return (1);
}
