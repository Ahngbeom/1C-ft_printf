/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:49:25 by bahn              #+#    #+#             */
/*   Updated: 2021/01/25 20:57:31 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	width_sort(char *fmt, va_list ap)
{
	//size_t	print_len;

	//print_len = 0;
	if (*fmt == '-')
	{
		//printf("\nw&s : %d\n", ft_atoi(++fmt));
		//printf("%d\n", va_arg(ap, int));
		//int_format(ap);
		//ft_strlen(ft_itoa(va_arg(ap, int)))
		return (data_type(*(ft_strchr_set(fmt, "csidpuxX%")), ap));
	}
	else
	{
		//printf("\nw&s : %d\n", ft_atoi(fmt));
		return (data_type(*(ft_strchr_set(fmt, "csidpuxX%")), ap));
	}
}
