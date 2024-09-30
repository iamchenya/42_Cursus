/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:07:57 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/28 14:31:36 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		print_char(char c);
size_t	ft_strlen(const char *s);
int		print_string(char *str);
int		print_digit_base(long nbr, int base, char *digit);
int		print_pointer(void *pointer, int pre);

#endif
