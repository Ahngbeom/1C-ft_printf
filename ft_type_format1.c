/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_format1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:00:24 by bahn              #+#    #+#             */
/*   Updated: 2021/01/31 04:16:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*str;

	if (size != 0)
	{
		str = ft_calloc(sizeof(char), ft_abs(size) + 1);
		ft_memset(str, pdg, ft_abs(size));
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
	char	*arg;
	char	*padding;
	char	*result;

	arg = ft_strdup(va_arg(ap, char *));
	if (size != 0 && ft_strlen(arg) < ft_abs(size))
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

size_t	int_format(va_list ap, int size, char pdg)
{
	size_t	print_len;
	char	*arg;
	char	*padding;
	char	*result;

	arg = ft_itoa(va_arg(ap, int));
	if (size != 0 && ft_strlen(arg) < ft_abs(size))
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
