/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:43:33 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/09 01:10:44 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	find;
	int		len;

	str = (char *)s;
	find = (char)c;
	len = ft_strlen(s);
	if (find == '\0')
		return (&str[len]);
	while (len >= 0)
	{
		if (str[len] == find)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
