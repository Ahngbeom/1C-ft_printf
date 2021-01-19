/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:27:23 by bahn              #+#    #+#             */
/*   Updated: 2021/01/19 15:50:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);

void	char_format(va_list ap);
void	str_format(va_list ap);
void	int_format(va_list ap);
void	double_format(va_list ap);
void	pointer_format(va_list ap);
void	uint_format(va_list ap);
void	uhexal_format(va_list ap);
void	uhexau_format(va_list ap);

#endif
