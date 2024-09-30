/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:31:27 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/28 14:39:35 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *pointer, int pre)
{
	unsigned long	tmp;
	unsigned int	count;
	char			*digit;

	tmp = (unsigned long)pointer;
	count = 0;
	digit = "0123456789abcdef";
	if (tmp == 0 && pre == 1)
		return (print_string("(nil)"));
	if (pre == 1)
	{
		count += print_string("0x");
		pre = 0;
	}
	if (tmp < 16)
		return (count += print_char(digit[tmp]));
	else
	{
		count += print_pointer((void *)(tmp / 16), pre);
		return (count += print_pointer((void *)(tmp % 16), pre));
	}
}
