/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_format1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:00:24 by bahn              #+#    #+#             */
/*   Updated: 2021/01/28 20:03:15 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (size != 0)
	{
		str = ft_calloc(sizeof(char), ft_absolute(size) + 1);
		ft_memset(str, pdg, ft_absolute(size));
		if (size < 0)
			*str = va_arg(ap, int);
		if (size > 0)
			str[size - 1] = va_arg(ap, int);
		print_len = ft_putstr_fd(str, 1);
		free(str);
	}
	else
		print_len = ft_putchar_fd(va_arg(ap, int), 1);
	return (print_len);
}

size_t	str_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (size != 0)
	{
		str = ft_strdup(va_arg(ap, char *));
		print_len = set_padding(str, size, pdg);
	}
	else
		print_len = ft_putstr_fd(va_arg(ap, char *), 1);
	return (print_len);
}

size_t	int_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (size != 0)
	{
		str = ft_itoa(va_arg(ap, int));
		print_len = set_padding(str, size, pdg);
	}
	else
		print_len = ft_putnbr_fd(va_arg(ap, int), 1);
	return (print_len);
}
