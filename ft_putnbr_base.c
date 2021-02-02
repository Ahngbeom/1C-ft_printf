/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:03:47 by bahn              #+#    #+#             */
/*   Updated: 2021/02/01 20:39:23 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_dupl_check(char *str, int length)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static	size_t	ft_putnbr(long long nbr, char *base, int base_count)
{
	size_t	print_len;

	print_len = 0;
	if (nbr >= 0)
	{
		if (nbr / base_count < base_count)
			print_len += ft_putchar_fd(base[nbr / base_count], 1);
		else if (nbr / base_count >= base_count)
			print_len += ft_putnbr(nbr / base_count, base, base_count);
		print_len += ft_putchar_fd(base[nbr % base_count], 1);
	}
	else
	{
		print_len += ft_putchar_fd('-', 1);
		if ((nbr / base_count) * -1 < base_count)
			print_len += ft_putchar_fd(base[(nbr / base_count) * -1], 1);
		else if ((nbr / base_count) * -1 >= base_count)
			print_len += ft_putnbr((nbr / base_count) * -1, base, base_count);
		print_len += ft_putchar_fd(base[(nbr % base_count) * -1], 1);
	}
	return (print_len);
}

size_t		ft_putnbr_base(long long nbr, char *base)
{
	int base_count;

	base_count = 0;
	while (base[base_count] != '\0')
	{
		if (base[base_count] == '-' || base[base_count] == '+')
		{
			ft_putchar_fd('\0', 1);
			return (-1);
		}
		base_count++;
	}
	if (base_count < 2)
		return (-1);
	else if (ft_dupl_check(base, base_count))
		return (-1);
	else
		return (ft_putnbr(nbr, base, base_count));
}
