/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/31 03:41:54 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	data_type(char type, va_list ap, int size, char pdg)
{
	size_t	print_len;

	if (type == 'c')
		return (char_format(ap, size, pdg));
	else if (type == 's')
		return (str_format(ap, size, pdg));
	else if (type == 'i' || type == 'd')
		return (int_format(ap, size, pdg));
	else if (type == 'p')
		return (pointer_format(ap, size, pdg));
	else if (type == 'u')
		return (uint_format(ap, size, pdg));
	else if (type == 'x' || type == 'X')
		return (uhex_format(type, ap, size, pdg));
	else if (type == '%')
		print_len = ft_putchar_fd(type, 1);
	return (print_len);
}

static	size_t	find_format(char *fmt, va_list ap)
{
	char	*ptr;

	ptr = fmt;
	if (*ptr == '-' || (*ptr >= '1' && *ptr <= '9'))
		return (data_type(*(ft_strchr_set(fmt, "csidpuxX%")),
					ap, ft_atoi(fmt), ' '));
	else if (*ptr == '0' || (*ptr >= '1' && *ptr <= '9'))
		return (data_type(*(ft_strchr_set(fmt, "csidpuxX%")),
					ap, ft_atoi(fmt), '0'));
	else
		return (data_type(*ptr, ap, 0, '\0'));
}

int			ft_printf(const char *str, ...)
{
	int		rtn;
	va_list		ap;

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
