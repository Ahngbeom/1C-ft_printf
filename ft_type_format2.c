/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_format2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:00:24 by bahn              #+#    #+#             */
/*   Updated: 2021/01/28 20:15:10 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pointer_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*addr;
	char	*hex;

	addr = ft_strdup("0x");
	hex = ft_tobase_n(va_arg(ap, long long), "0123456789abcdef");
	ft_strlcat(addr, hex, ft_strlen(addr) + ft_strlen(hex) + 1);
	if (size != 0)
		print_len = set_padding(addr, size, pdg);
	else
	{
		print_len = ft_putstr_fd(addr, 1);
		free(addr);
	}
	return (print_len);
}

size_t	uint_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (size != 0)
	{
		str = ft_itoa(va_arg(ap, unsigned int));
		print_len = set_padding(str, size, pdg);
	}
	else
		print_len = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	return (print_len);
}

size_t	uhex_format(char type, va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (type == 'x')
		str = ft_tobase_n(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		str = ft_tobase_n(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (size != 0)
		print_len = set_padding(str, size, pdg);
	else
	{
		print_len = ft_putstr_fd(str, 1);
		free(str);
	}
	return (print_len);
}
