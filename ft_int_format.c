/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:50:07 by bahn              #+#    #+#             */
/*   Updated: 2021/02/03 20:56:35 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	set_precision(int prec, char *arg, char *padding)
{
	size_t	print_len;

	print_len = 0;
	if (prec > -1 && (size_t)prec > ft_strlen(arg))
	{
		padding = set_padding(1, prec - ft_strlen(arg));
		print_len = ft_strlen(padding);
		arg = set_sorting(0, arg, padding);
	}
	return (print_len);
}

size_t  int_format(int n, t_opt *opt)
{
	size_t  print_len;
	char    *sign;
	char    *arg;
	char    *padding;

	print_len = 0;
	sign = ft_strdup("");
	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else if (n < 0)
	{
		sign = ft_strjoin(sign, ft_strdup("-"));
		print_len += ft_strlen(sign);
		arg = ft_itoa((long long)n * -1);
	}
	else
		arg = ft_itoa(n);
	print_len += ft_strlen(arg);
	/*
	if (opt->prec > -1 && (size_t)opt->prec > ft_strlen(arg))
	{
		padding = set_padding(1, opt->prec - ft_strlen(arg));
		print_len += ft_strlen(padding);
		arg = set_sorting(0, arg, padding);
	}
	*/
	print_len += set_precision(opt->prec, arg, padding);
	if (opt->width > 0 && (size_t)opt->width > print_len && opt->width > opt->prec)
	{
		padding = set_padding(opt->zero, opt->width - print_len);
		print_len += ft_strlen(padding);
		if (opt->zero > 0)
			padding = ft_strjoin(sign, padding);
		else
			arg = ft_strjoin(sign, arg);
		arg = set_sorting(opt->minus, arg, padding);
	}
	else
		arg = ft_strjoin(sign, arg);
	ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}
