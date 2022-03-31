/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:24:02 by halhashm          #+#    #+#             */
/*   Updated: 2021/10/24 14:21:16 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *d, const char *s, size_t l)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (l == 0)
		return (NULL);
	while (s[i] && i < l - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

static int	ft_cwords(char const *s, char c)
{
	unsigned int	i;
	int				ic;

	i = 0;
	ic = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			ic++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (ic);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tb;

	i = 0;
	j = 0;
	k = 0;
	tb = (char **)malloc(sizeof(char *) * (ft_cwords(s, c)) + 1);
	if (tb == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tb[k++] = ft_strndup(s + j, i - j);
	}
	tb[k] = "\0";
	return (tb);
}
