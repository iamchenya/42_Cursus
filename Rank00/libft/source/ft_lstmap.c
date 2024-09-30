/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:55:02 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/18 02:56:21 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew(f(lst -> content));
	if (head == NULL)
		return (NULL);
	node = head;
	lst = lst -> next;
	while (lst != NULL)
	{
		node -> next = ft_lstnew(f(lst -> content));
		if (node -> next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		node = node -> next;
		lst = lst -> next;
	}
	node -> next = NULL;
	return (head);
}
