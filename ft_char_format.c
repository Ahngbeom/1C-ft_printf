/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:17:21 by bahn              #+#    #+#             */
/*   Updated: 2021/02/08 15:17:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_format(int ch, t_opt *opt)
{
	size_t	print_len;
	char	*padding;

	if (opt->width > 0)
		padding = set_padding(opt->zero, (size_t)opt->width - sizeof(char));
	else
		padding = ft_strdup("");
	if (opt->minus == 0)
	{
		print_len = ft_putstr_fd(padding, 1);
		print_len += ft_putchar_fd((char)ch, 1);
	}
	else
	{
		print_len = ft_putchar_fd((char)ch, 1);
		print_len += ft_putstr_fd(padding, 1);
	}
	free(padding);
	return (print_len);
}

size_t	str_format(char *str, t_opt *opt)
{
	size_t	print_len;
	char	*arg;
	char	*padding;

	if (str == NULL)
	{
		str = "(null)";
	//	if (opt->prec != -1 && opt->prec < (int)ft_strlen(str))
	//		str = "";
	}
	if (opt->prec > -1)
		arg = ft_substr(str, 0, opt->prec);
	else
		arg = ft_strdup(str);
	if (opt->width > 0 && (size_t)opt->width > ft_strlen(arg))
	{
		padding = set_padding(0, opt->width - ft_strlen(arg));
		arg = set_sorting(opt->minus, arg, padding);
	}
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}
