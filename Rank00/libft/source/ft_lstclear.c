/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:08:13 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/18 00:52:17 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst == NULL || del == NULL)
		return ;
	while ((*lst)->next != NULL)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
