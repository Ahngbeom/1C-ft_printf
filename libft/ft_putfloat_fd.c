/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:04:05 by bahn              #+#    #+#             */
/*   Updated: 2021/01/18 21:43:15 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
void	ft_putfloat_fd(float n, int fd)
{
	int int_part;
	int fract_part;

	if (fd < 0)
		return ;
	int_part = (int)n;
	fract_part = (n - int_part) * 1000000;

	printf("integer part : %d\n", int_part);
	printf("fractional part : %d\n", fract_part);

	/*
	if (fd < 0)
		return ;
	if (n >= 0)
	{
		if (n / 10 >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd('0' + (n % 10), fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		if ((n / 10) * -1 > 0)
			ft_putnbr_fd((n / 10) * -1, fd);
		ft_putchar_fd('0' + ((n % 10) * -1), fd);
	}
	*/
}

int	main()
{
	ft_putfloat_fd(123456.123456, 1);
	printf("%f\n", 123.4567896);
	return (0);
}
