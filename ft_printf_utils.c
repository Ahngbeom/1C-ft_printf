/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/01/26 00:11:02 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (size > 0)
	{
		str = ft_calloc(sizeof(char), size);
		ft_memset(str, pdg, size);
		str[size - 1] = va_arg(ap, int);
		print_len = ft_putstr_fd(str, 1);
		free(str);
	}
	else if (size < 0)
	{
		str = ft_calloc(sizeof(char), ft_absolute(size));
		ft_memset(str, pdg, size);
		*str = va_arg(ap, int);
		print_len = ft_putstr_fd(str, 1);
		free(str);
	}
	else
		print_len = ft_putchar_fd(va_arg(ap, int), 1);
	return (print_len);
}

size_t	str_format(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	return (ft_putstr_fd(str, 1));
}

size_t	int_format(va_list ap, int size, char pdg)
{
	/*
	int	num;

	num = va_arg(ap, int);
	return (ft_putnbr_fd(num, 1));
	*/
	size_t	print_len;
	char	*str;
	char	*padding;

	str = ft_itoa(va_arg(ap, int));
	padding = malloc(size - ft_strlen(str) + 1);
	ft_memset(padding, pdg, size - ft_strlen(str));
	ft_strlcat(str, padding, size + 1);
	free(padding);
	print_len = ft_putstr_fd(str, 1);
	free(str);
	return (print_len);
}

size_t	pointer_format(va_list ap)
{
	long long       addr;

	addr = va_arg(ap, long long);
	return (ft_putstr_fd("0x", 1) + ft_putnbr_base(addr, "0123456789abcdef"));
}

size_t    unsigned_format(char fmt, va_list ap)
{
	unsigned int    num;

	num = va_arg(ap, unsigned int);
	if (fmt == 'u')
		return (ft_putnbr_unsigned(num));
	else if (fmt == 'x')
		return (ft_putnbr_base(num, "0123456789abcdef"));
	else if (fmt == 'X')
		return (ft_putnbr_base(num, "0123456789ABCDEF"));
	else
		return (-1);
}
