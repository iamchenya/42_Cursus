/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:37:16 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/28 14:51:22 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list ap)
{
	unsigned int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(ap, int));
	else if (format == 's')
		count += print_string(va_arg(ap, char *));
	else if (format == 'p')
		count += print_pointer(va_arg(ap, void *), 1);
	else if (format == 'd' || format == 'i')
		count += print_digit_base(va_arg(ap, int), 10, "0123456789");
	else if (format == 'u')
		count += print_digit_base(va_arg(ap, unsigned int), 10, "0123456789");
	else if (format == 'x')
		count += print_digit_base(va_arg(ap, unsigned int), \
		16, "0123456789abcdef");
	else if (format == 'X')
		count += print_digit_base(va_arg(ap, unsigned int), \
		16, "0123456789ABCDEF");
	else if (format == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	count;
	va_list			ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += check_format(*(++format), ap);
		else
			count += print_char(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	result;

	result = ft_printf("%c %c %c %c\n", 'd', NULL, 0, '%');
	printf("%c %c %c %c\n", 'd', NULL, 0, '%');
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%s %s\n", NULL, "hello world");
	printf("%s %s\n", NULL, "hello world");
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%p %p %p %p %p\n", 0, INT_MAX, INT_MIN, 16, "hello");
	printf("%p %p %p %p %p\n", 0, INT_MAX, INT_MIN, 16, "hello");
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%d %d %d %d %d\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf("%d %d %d %d %d\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%u %u %u %u %u\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf("%u %u %u %u %u\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%x %x %x %x %x\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf("%x %x %x %x %x\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%X %X %X %X %X\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf("%X %X %X %X %X\n", INT_MIN, INT_MAX, 0, -5678, 34567);
	printf(" \ncount: %d\n\n", result);
	//
	result = ft_printf("%% %%\n", '%', "5%");
	printf("%% %%\n", '%', "5%");
	printf(" \ncount: %d\n\n", result);
	//
	return (0);
}*/
