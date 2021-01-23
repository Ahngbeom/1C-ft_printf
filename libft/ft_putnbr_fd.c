/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:59:00 by bahn              #+#    #+#             */
/*   Updated: 2021/01/23 15:59:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t print_len;

	print_len = 0;
	if (fd < 0)
		return (-1);
	if (n >= 0)
	{
		if (n / 10 > 0)
			print_len += ft_putnbr_fd(n / 10, fd);
		print_len += ft_putchar_fd('0' + (n % 10), fd);
	}
	else
	{
		print_len += ft_putchar_fd('-', fd);
		if ((n / 10) * -1 > 0)
			print_len += ft_putnbr_fd((n / 10) * -1, fd);
		print_len += ft_putchar_fd('0' + ((n % 10) * -1), fd);
	}
	return (print_len);
}
