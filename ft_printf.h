/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:27:23 by bahn              #+#    #+#             */
/*   Updated: 2021/01/25 22:36:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);

size_t	char_format(va_list ap, int size, char pdg);
size_t	str_format(va_list ap);
size_t	int_format(va_list ap);
size_t	pointer_format(va_list ap);
size_t	unsigned_format(char fmt, va_list ap);
size_t	data_type(char type, va_list ap, int size, char pdg);
size_t	width_sort(char *fmt, va_list ap);

#endif
