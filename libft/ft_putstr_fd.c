/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:23:07 by bahn              #+#    #+#             */
/*   Updated: 2021/01/23 17:04:51 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *c, int fd)
{
	size_t	print_len;

	print_len = 0;
	if (fd < 0)
		return (-1);
	while (c && *c != '\0')
	{
		if (ft_isascii(*c))
			print_len += write(fd, c++, 1);
		else
			return (-1);
	}
	return (print_len);
}
