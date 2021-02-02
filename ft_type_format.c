/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:00:24 by bahn              #+#    #+#             */
/*   Updated: 2021/02/02 18:18:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_format(int ch, t_opt *opt)
{
	size_t	print_len;
	char	*str;

	if (opt->width > 0)
	{
		str = set_padding(opt->zero, (size_t)opt->width);
		if (opt->minus == 0)
			str[opt->width - 1] = (char)ch;
		else
			*str = (char)ch;
		print_len = ft_putstr_fd(str, 1);
		free(str);
	}
	else
		print_len = ft_putchar_fd((char)ch, 1);
	return (print_len);
}

size_t	str_format(char *str, t_opt *opt)
{
	size_t	print_len;
	char	*arg;
	char	*padding;
	char	*result;

	arg = ft_strdup(str);
	if (opt->width > 0 && ft_strlen(arg) < (size_t)opt->width)
	{
		padding = set_padding(opt->zero, opt->width - ft_strlen(arg));
		result = set_sorting(opt->minus, arg, padding);
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

size_t	int_format(int n, t_opt *opt)
{
	size_t	print_len;
	char	*arg;
	char	*padding;
	char	*result;

	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else
		arg = ft_itoa(n);
	if (opt->width > 0 && ft_strlen(arg) < (size_t)opt->width)
	{
		padding = set_padding(opt->zero, opt->width - ft_strlen(arg));
		result = set_sorting(opt->minus, arg, padding);
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

size_t  pointer_format(long long n, t_opt *opt)
{
	size_t  print_len;
	char    *addr;
	char    *padding;
	char    *result;

	addr = ft_strjoin(ft_strdup("0x"), ft_tobase_n(n, "0123456789abcdef"));
	if (opt->width > 0)
	{
		padding = set_padding(opt->zero, opt->width - ft_strlen(addr));
		result = set_sorting(opt->minus, addr, padding);
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

size_t  uint_format(unsigned int n, t_opt *opt)
{
	size_t  print_len;
	char    *arg;
	char    *padding;
	char    *result;

	if (opt->type == 'u')
		arg = ft_itoa(n);
	else if (opt->type == 'x')
		arg = ft_tobase_n(n, "0123456789abcdef");
	else if (opt->type == 'X')
		arg = ft_tobase_n(n, "0123456789ABCDEF");
	if (opt->width > 0)
	{
		padding = set_padding(opt->zero, opt->width - ft_strlen(arg));
		result = set_sorting(opt->minus, arg, padding);
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