/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/18 20:07:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_format(char fmt, va_list ap)
{
	if (fmt == 'c')
		char_format(ap);
	else if (fmt == 's')
		str_format(ap);
	else if (fmt == 'd')
		double_format(ap);
	else if (fmt == 'i')
		int_format(ap);
	else if (fmt == 'f')
		float_format(ap);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			ft_putchar_fd(*str, 1);
		else
			find_format(*(++str), ap);
		str++;
	}
	va_end(ap);
	return (0);
}

int	main()
{
	printf("printf	  : %c %s %i %d %f\n", 'w', "zzzz", 5, 6, 1234.567);
	ft_printf("ft_printf : %c %s %i %d %f\n", 'w', "zzzz", 5, 6, 1234.567);
	
	return (0);
}
