/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:00:47 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/10 18:05:50 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_cinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	ft_fstpos(char const *src, char const *set)
{
	size_t	fst;

	fst = 0;
	while (src[fst] != '\0')
	{
		if (ft_cinset(src[fst], set) == 0)
			return (fst);
		fst++;
	}
	return (fst);
}

static char	ft_lstpos(char const *src, char const *set)
{
	size_t	lst;

	lst = ft_strlen(src);
	while (lst > 0)
	{
		if (ft_cinset(src[lst - 1], set) == 0)
			return (lst);
		lst--;
	}
	return (lst + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	fstpos;
	size_t	lstpos;
	size_t	size;

	fstpos = ft_fstpos(s1, set);
	lstpos = ft_lstpos(s1, set);
	size = lstpos - fstpos;
	dest = ft_substr(s1, fstpos, size);
	return (dest);
}
