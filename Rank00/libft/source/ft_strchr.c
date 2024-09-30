/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:00:59 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/16 17:37:53 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	find;
	int		i;

	str = (char *)s;
	find = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return (&str[i]);
		i++;
	}
	if (find == '\0')
		return (&str[i]);
	return (NULL);
}
