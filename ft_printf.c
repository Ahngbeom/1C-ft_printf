/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/23 16:45:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_format(char fmt, va_list ap)
{
	size_t	print_len;

	if (fmt == 'c')
		print_len = char_format(ap);
	else if (fmt == 's')
		print_len = str_format(ap);
	else if (fmt == 'i' || fmt == 'd')
		print_len = int_format(ap);
	else if (fmt == 'p')
		print_len = pointer_format(ap);
	else if (fmt == 'u' || fmt == 'x' || fmt == 'X')
		unsigned_format(fmt, ap);
	else if (fmt == '%')
		print_len = ft_putchar_fd(fmt, 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int	rtn;
	va_list ap;

	rtn = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			rtn += ft_putchar_fd(*str, 1);
		else
			rtn += find_format(*(++str), ap);
		str++;
	}
	va_end(ap);
	return (rtn);
}
