/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:49:43 by halhashm          #+#    #+#             */
/*   Updated: 2021/10/05 10:19:15 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*st;

	st = s;
	while (*s)
		s++;
	while (st >= s)
		if (*s-- == (char)c)
			return ((char *)s + 1);
	return (NULL);
}
