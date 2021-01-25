/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/25 20:08:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//gccw libft/ft_* ./*.c src/main.c

int	main()
{

	printf("\n===================파라미터 옵션 테스트========================\n");
	printf("(return : %d)\n", printf("1 : %-5d, 2 : %5c ", -123, 'b'));
	printf("(return : %d)\n", ft_printf("1 : %-5d, 2 : %5c ", -123, 'b'));

/*
	printf("\n===================데이터 타입 테스트========================\n");
	printf("(return : %d)\n", printf("Only text"));
	printf("(return : %d)\n", ft_printf("Only text"));
	printf("(return : %d)\n", printf("%c", 'A'));
	printf("(return : %d)\n", ft_printf("%c", 'A'));
	printf("(return : %d)\n", printf("%s", "abcde12345"));
	printf("(return : %d)\n", ft_printf("%s", "abcde12345"));
	printf("(return : %d)\n", printf("%p", "memory address"));
	printf("(return : %d)\n", ft_printf("%p", "memory address"));
	printf("(return : %d)\n", printf("%d", 12345));
	printf("(return : %d)\n", ft_printf("%d", 12345));
	printf("(return : %d)\n", printf("%i", 67890));
	printf("(return : %d)\n", ft_printf("%i", 67890));
	printf("(return : %d)\n", printf("%u", -1234));
	printf("(return : %d)\n", ft_printf("%u", -1234));
	printf("(return : %d)\n", printf("%x", 255));
	printf("(return : %d)\n", ft_printf("%x", 255));
	printf("(return : %d)\n", printf("%X", 255));
	printf("(return : %d)\n", ft_printf("%X", 255));
	printf("(return : %d)\n", printf("%%"));
	printf("(return : %d)\n", ft_printf("%%"));
*/
	return (0);
}
