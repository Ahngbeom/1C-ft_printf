/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/19 16:11:57 by bahn             ###   ########.fr       */
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
	else if (fmt == 'p')
		pointer_format(ap);
	else if (fmt == 'u')
		uint_format(ap);
	else if (fmt == 'x')
		uhexal_format(ap);
	else if (fmt == 'X')
		uhexau_format(ap);
}

int	ft_printf(const char *str, ...)
{
	int	rtn;
	va_list ap;

	rtn = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			ft_putchar_fd(*str, 1);
		else
			find_format(*(++str), ap);
		str++;
		rtn++;
	}
	va_end(ap);
	return (rtn);
}

int	main()
{
	char	str[5] = "abcde";
	char	*ptr;
	int	rtn;

	ptr = str;

	rtn = printf("printf	  : %c %s %i %d %p %u %x %X\n", 'w', "zzzz", 5, 6, ptr, -123, 555, 555);

	printf("printf return : %d\n", rtn);
	ft_printf("ft_printf : %c %s %i %d %p %u %x %X\n", 'w', "zzzz", 5, 6, ptr, -123, 555, 555);
	printf("ft_printf return : %d\n", rtn);
	
	return (0);
}
