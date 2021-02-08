/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:16:30 by bahn              #+#    #+#             */
/*   Updated: 2021/02/08 21:08:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	*init_opt(void)
{
	t_opt	*opt;

	if (!(opt = malloc(sizeof(t_opt))))
		return (NULL);
	ft_memset(opt, 0, sizeof(t_opt));
	opt->prec = -1;
	return (opt);
}

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
	char	*result;

	if (mns_flg == 0)
	{
		result = ft_strjoin(padding, arg);
		return (result);
	}
	else
	{
		result = ft_strjoin(arg, padding);
		return (result);
	}
}
