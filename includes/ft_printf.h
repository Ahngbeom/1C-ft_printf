/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:27:23 by bahn              #+#    #+#             */
/*   Updated: 2021/02/10 14:13:14 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define DTYPE "csdiupxX%"

typedef struct	s_opt
{
	size_t		minus;
	size_t		zero;
	int			width;
	int			prec;
	char		type;
}				t_opt;

int				ft_printf(const char *str, ...);

size_t			char_format(int ch, t_opt *opt);
size_t			str_format(char	*str, t_opt *opt);
size_t			int_format(int n, t_opt *opt);
size_t			pointer_format(long long n, t_opt *opt);
size_t			uint_format(unsigned int n, t_opt *opt);

t_opt			*init_opt(void);
char			*set_padding(size_t zr_flg, size_t size);
char			*set_sorting(size_t mns_flg, char *arg, char *padding);

size_t			ft_putnbr_base(long long nbr, char *base);
size_t			ft_putnbr_unsigned(unsigned int	n);
char			*ft_strchr_set(char *str, char *set);
char			*ft_tobase_n(long long n, char *base);

#endif
