/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:20:42 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/28 14:31:16 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit_base(long nbr, int base, char *digit)
{
	unsigned int	count;

	count = 0;
	if (nbr < 0)
	{
		print_char('-');
		count++;
		return (count += print_digit_base(-nbr, base, digit));
	}
	else if (nbr < base)
		return (count += print_char(digit[nbr]));
	else
	{
		count += print_digit_base(nbr / base, base, digit);
		return (count += print_digit_base(nbr % base, base, digit));
	}
}
