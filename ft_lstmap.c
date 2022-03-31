/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:03:02 by halhashm          #+#    #+#             */
/*   Updated: 2021/10/23 21:03:05 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*bonus;
	t_list	*dublist;
	t_list	*dubrez;

	if (!lst || !f)
		return (NULL);
	dublist = lst;
	bonus = NULL;
	while (dublist)
	{
		if (f(dublist->content))
		{
			dubrez = ft_lstnew(f(dublist->content));
			if (!dubrez)
			{
				ft_lstclear(&bonus, del);
				return (NULL);
			}
			ft_lstadd_back(&bonus, dubrez);
		}
		dublist = dublist->next;
	}
	return (bonus);
}
