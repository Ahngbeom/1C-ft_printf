/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:50:07 by bahn              #+#    #+#             */
/*   Updated: 2021/02/08 19:57:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*applies_to_width(t_opt *opt, char *sign, char *arg)
{
	char	*padding;

	if (opt->width > 0 &&
			(size_t)opt->width > (ft_strlen(sign) + ft_strlen(arg)) &&
			opt->width > opt->prec)
	{
		padding = set_padding(opt->zero,
				opt->width - (ft_strlen(sign) + ft_strlen(arg)));
		if (opt->zero > 0)
			padding = ft_strjoin(sign, padding);
		else
			arg = ft_strjoin(sign, arg);
		arg = set_sorting(opt->minus, arg, padding);
	}
	else
		arg = ft_strjoin(sign, arg);
	return (arg);
}

static	char	*applies_to_prec(int prec, char *arg)
{
	char	*padding;

	if (prec > -1 && (size_t)prec > ft_strlen(arg))
	{
		padding = set_padding(1, prec - ft_strlen(arg));
		arg = set_sorting(0, arg, padding);
	}
	return (arg);
}

size_t			int_format(int n, t_opt *opt)
{
	size_t	print_len;
	char	*sign;
	char	*arg;

	sign = ft_strdup("");
	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else if (n < 0)
	{
		sign = ft_strjoin(sign, ft_strdup("-"));
		arg = ft_itoa((long long)n * -1);
	}
	else
		arg = ft_itoa(n);
	arg = applies_to_prec(opt->prec, arg);
	arg = applies_to_width(opt, sign, arg);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}

size_t			uint_format(unsigned int n, t_opt *opt)
{
	size_t	print_len;
	char	*arg;

	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else if (opt->type == 'u')
		arg = ft_itoa(n);
	else if (opt->type == 'x')
		arg = ft_tobase_n(n, "0123456789abcdef");
	else if (opt->type == 'X')
		arg = ft_tobase_n(n, "0123456789ABCDEF");
	else
		return (0);
	arg = applies_to_prec(opt->prec, arg);
	arg = applies_to_width(opt, ft_strdup(""), arg);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}

size_t			pointer_format(long long n, t_opt *opt)
{
	size_t	print_len;
	char	*addr;

	if (n == 0 && opt->prec == 0)
		addr = ft_strdup("");
	else if (n == 0 && opt->prec == -1)
		addr = ft_strdup("0");
	else
		addr = ft_tobase_n(n, "0123456789abcdef");
	addr = applies_to_prec(opt->prec, addr);
	addr = ft_strjoin(ft_strdup("0x"), addr);
	addr = applies_to_width(opt, ft_strdup(""), addr);
	print_len = ft_putstr_fd(addr, 1);
	free(addr);
	return (print_len);
}
