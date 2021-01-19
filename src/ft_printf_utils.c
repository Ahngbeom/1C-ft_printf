/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/01/19 15:50:25 by bahn             ###   ########.fr       */
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

void	pointer_format(va_list ap)
{
	long long	addr;

	addr = va_arg(ap, long long);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(addr, "0123456789abcdef");
}

void	uint_format(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putnbr_unsigned(num);
}

void	uhexal_format(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putnbr_base(num, "0123456789abcdef");
}

void	uhexau_format(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putnbr_base(num, "0123456789ABCDEF");
}

