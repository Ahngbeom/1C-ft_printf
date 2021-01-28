/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/01/28 18:01:51 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	set_padding(char *str, int size, char pdg)
{
	size_t	print_len;
	char	*padding;

	padding = ft_calloc(sizeof(char), ft_absolute(size) - ft_strlen(str) + 1);
	ft_memset(padding, pdg, ft_absolute(size) - ft_strlen(str));
	if (size < 0)
	{
		ft_strlcat(str, padding, ft_absolute(size) + 1);
		print_len = ft_putstr_fd(str, 1);
		free(str);
	}
	else if (size > 0)
	{
		ft_strlcat(padding, str, ft_absolute(size) + 1);
		print_len = ft_putstr_fd(padding, 1);
		free(padding);
	}
	return (print_len);
}
