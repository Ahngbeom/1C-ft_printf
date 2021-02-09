/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:54:12 by bahn              #+#    #+#             */
/*   Updated: 2021/02/08 22:03:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_dupl_check(char *str, int length)
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

static	char	*ft_putnbr(long long nbr, char *base,
		int base_count, char *result)
{
	char	*hex;

	if (nbr >= 0)
	{
		if (nbr / base_count < base_count)
		{
			if (nbr / base_count != 0)
			{
				hex = ft_substr(base, nbr / base_count, 1);
				result = ft_strjoin(result, hex);
			}
		}
		else
			result = ft_putnbr(nbr / base_count, base, base_count, result);
		hex = ft_substr(base, nbr % base_count, 1);
		result = ft_strjoin(result, hex);
	}
	return (result);
}

char			*ft_tobase_n(long long n, char *base)
{
	char	*result;
	int		base_count;

	base_count = 0;
	while (base[base_count] != '\0')
	{
		if (base[base_count] == '-' || base[base_count] == '+')
		{
			ft_putchar_fd('\0', 1);
			return (NULL);
		}
		base_count++;
	}
	if (base_count < 2)
		return (NULL);
	else if (ft_dupl_check(base, base_count))
		return (NULL);
	else
	{
		result = ft_calloc(sizeof(char), 1);
		result = ft_putnbr(n, base, base_count, result);
	}
	return (result);
}
