/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/01/21 16:12:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

