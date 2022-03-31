/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:55:06 by halhashm          #+#    #+#             */
/*   Updated: 2021/10/24 14:16:29 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*e;

	e = 0;
	if (!lst)
		return (0);
	while (*lst)
	{
		e = *lst;
		*lst = (*lst)->next;
		del((e)->content);
		free(e);
	}
}
