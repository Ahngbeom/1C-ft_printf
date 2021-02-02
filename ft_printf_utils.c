/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/02/02 16:16:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_padding(size_t zr_flg, size_t size)
{
	char	*padding;

	padding = ft_calloc(sizeof(char), size + 1);
	if (zr_flg == 0)
		ft_memset(padding, ' ', size);
	else
		ft_memset(padding, '0', size);
	return (padding);
}

char	*set_sorting(size_t mns_flg, char *arg, char *padding)
{
	if(mns_flg == 0)
		return (ft_strjoin(padding, arg));
	else
		return (ft_strjoin(arg, padding));
}
