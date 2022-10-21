/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:44:58 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:45:00 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(&lst->content);
		lst = lst->next;
	}
}
