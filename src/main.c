/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:21:34 by bahn              #+#    #+#             */
/*   Updated: 2021/01/29 20:44:34 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//gccw libft/ft_* ./*.c src/main.c

int	main()
{
	char	*str;

	str = ft_strdup("String");
	
	printf("\n===================파라미터 옵션 테스트========================\n");
	printf(" - (return : %d)\n", printf("   print : |%c|, |%5c|, |%-5c|", 'b', 'b', 'b'));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%c|, |%5c|, |%-5c|", 'b', 'b', 'b'));
	printf(" - (return : %d)\n", printf("   print : |%s|, |%10s|, |%-10s|", str, str, str));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%s|, |%10s|, |%-10s|", str, str, str));
	printf(" - (return : %d)\n", printf("   print : |%d|, |%5d|, |%-5d|", -123, -123, -123));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%d|, |%5d|, |%-5d|", -123, -123, -123));
	printf(" - (return : %d)\n", printf("   print : |%p|, |%20p|, |%-20p|", str, str, str));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%p|, |%20p|, |%-20p|", str, str, str));
	/*
	printf(" - (return : %d)\n", printf("   print : |%u|, |%20u|, |%-20u|", -5000, -5000, -5000));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%u|, |%20u|, |%-20u|", -5000, -5000, -5000));
	printf(" - (return : %d)\n", printf("   print : |%x|, |%20x|, |%-20x|", -5000, -5000, -5000));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%x|, |%20x|, |%-20x|", -5000, -5000, -5000));
	printf(" - (return : %d)\n", printf("   print : |%X|, |%20X|, |%-20X|", -5000, -5000, -5000));
	printf(" - (return : %d)\n", ft_printf("ft_print : |%X|, |%20X|, |%-20X|", -5000, -5000, -5000));
	*/

	free(str);

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
