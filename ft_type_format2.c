/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_format2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:00:24 by bahn              #+#    #+#             */
/*   Updated: 2021/01/30 20:33:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pointer_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*addr;
	char	*padding;
	char	*result;
	
	addr = ft_strjoin(ft_strdup("0x"), ft_tobase_n(va_arg(ap, long long), "0123456789abcdef"));
	if (size != 0)
	{
		padding = ft_calloc(sizeof(char), ft_abs(size) - ft_strlen(addr) + 1);
		ft_memset(padding, pdg, ft_abs(size) - ft_strlen(addr));
		if (size < 0)
			result = ft_strjoin(addr, padding);
		else
			result = ft_strjoin(padding, addr);
		print_len = ft_putstr_fd(result, 1);
		free(result);
	}
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
	char	*arg;
	char	*padding;
	char	*result;

	if (size != 0)
	{
		arg = ft_itoa(va_arg(ap, unsigned int));
		padding = ft_calloc(sizeof(char), ft_abs(size) - ft_strlen(arg) + 1);
		ft_memset(padding, pdg, ft_abs(size) - ft_strlen(arg));
		if (size < 0)
			result = ft_strjoin(arg, padding);
		else
			result = ft_strjoin(padding, arg);
		print_len = ft_putstr_fd(result, 1);
		free(result);
	}
	else
		print_len = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	return (print_len);
}

size_t	uhex_format(char type, va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*arg;
	char	*padding;
	char	*result;

	if (type == 'x')
		arg = ft_tobase_n(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		arg = ft_tobase_n(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (size != 0)
	{
		padding = ft_calloc(sizeof(char), ft_abs(size) - ft_strlen(arg) + 1);
		ft_memset(padding, pdg, ft_abs(size) - ft_strlen(arg));
		if (size < 0)
			result = ft_strjoin(arg, padding);
		else
			result = ft_strjoin(padding, arg);
		print_len = ft_putstr_fd(result, 1);
		free(result);
	}
	else
	{
		print_len = ft_putstr_fd(arg, 1);
		free(arg);
	}
	return (print_len);
}
