/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:03:47 by bahn              #+#    #+#             */
/*   Updated: 2021/01/19 16:07:02 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putbase(int n, char *base)
{
	ft_putchar(base[n]);
}

void	ft_putnbr(long long nbr, char *base, int base_count)
{
	if (nbr >= 0)
	{
		if (nbr / base_count < base_count)
			ft_putbase(nbr / base_count, base);
		else if (nbr / base_count >= base_count)
			ft_putnbr(nbr / base_count, base, base_count);
		ft_putbase(nbr % base_count, base);
	}
	else
	{
		ft_putchar('-');
		if ((nbr / base_count) * -1 < base_count)
			ft_putbase((nbr / base_count) * -1, base);
		else if ((nbr / base_count) * -1 >= base_count)
			ft_putnbr((nbr / base_count) * -1, base, base_count);
		ft_putbase((nbr % base_count) * -1, base);
	}
}

int		ft_dupl_check(char *str, int length)
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

void	ft_putnbr_base(long long nbr, char *base)
{
	int base_count;

	base_count = 0;
	while (base[base_count] != '\0')
	{
		if (base[base_count] == '-' || base[base_count] == '+')
		{
			ft_putchar('\0');
			return ;
		}
		base_count++;
	}
	if (base_count < 2)
		return ;
	else if (ft_dupl_check(base, base_count))
		return ;
	else
		ft_putnbr(nbr, base, base_count);
}
