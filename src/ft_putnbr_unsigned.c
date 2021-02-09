/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:29:04 by bahn              #+#    #+#             */
/*   Updated: 2021/02/01 20:39:38 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_unsigned(unsigned int n)
{
	size_t	print_len;

	print_len = 0;
	if (n / 10 > 0)
		print_len += ft_putnbr_fd(n / 10, 1);
	print_len += ft_putchar_fd('0' + (n % 10), 1);
	return (print_len);
}
