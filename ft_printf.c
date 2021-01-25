/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/25 22:35:50 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  data_type(char type, va_list ap, int size, char pdg)
{
	size_t  print_len;

	if (type == 'c')
		return (char_format(ap, size, pdg));
		//return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (type == 's')
		print_len = str_format(ap);
	else if (type == 'i' || type == 'd')
		print_len = int_format(ap);
	else if (type == 'p')
		print_len = pointer_format(ap);
	else if (type == 'u' || type == 'x' || type == 'X')
		print_len = unsigned_format(type, ap);
	else if (type == '%')
		print_len = ft_putchar_fd(type, 1);
	return (print_len);
}

size_t	find_format(char *fmt, va_list ap)
{
	char	*ptr;

	ptr = fmt;


	if (*ptr == '-' || (*ptr >= '1' && *ptr <= '9'))
		//ptr = width_sort(ptr, ap);
		return (width_sort(ptr, ap));
	else
		return (data_type(*ptr, ap, 0, '\0'));

	//return (data_type(*ptr, ap));
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
		{
			rtn += ft_putchar_fd(*str, 1);
			str++;
		}
		else
		{
			rtn += find_format((char *)++str, ap);
			str = ft_strchr_set((char *)str, "csidpuxX%") + 1;
		}
	}
	va_end(ap);
	return (rtn);
}
