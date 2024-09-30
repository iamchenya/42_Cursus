/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:07:08 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/09 17:03:53 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dst;
	size_t	total;

	total = nmemb * size;
	dst = (char *)malloc(total);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, total);
	return (dst);
}
