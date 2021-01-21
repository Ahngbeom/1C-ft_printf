/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/01/21 16:11:53 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_format(va_list ap)
{
	char	ch;

	ch = va_arg(ap, int);
	ft_putchar_fd(ch, 1);
}

void	str_format(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 1);
}

void	int_format(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr_fd(num, 1);
}

void	double_format(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr_fd(num, 1);
}
