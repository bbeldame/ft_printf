/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:33:44 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/18 00:13:48 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		main()
{
	int			r = 0;
	int			m = 0;

	setlocale(LC_ALL, "");

	wchar_t value = L'お';
	wchar_t *wstr = L"おはよう";
	char	c = 'A';

	r = printf("%4.15d", 42);
	printf("\nreal = %d\n", r);
	m = ft_printf("%4.15d", 42);
	printf("\nmy = %d\n", m);
//	r = printf("%.4d\n", 42);
//	printf("real = %d\n", r);
//	m = ft_printf("%.4d\n", 42);
//	printf("my = %d\n", m);
/*	r = printf("%lU\n", ULONG_MAX / 2);
	printf("real = %d\n", r);
	m = ft_printf("%U\n", ULONG_MAX / 2);
	printf("my = %d\n", m);
	r = printf("%lU\n", ULONG_MAX);
	printf("real = %d\n", r);
	m = ft_printf("%U\n", ULONG_MAX);
	printf("my = %d\n", m);
	r = printf("ok\n");
	printf("real = %d\n", r);
	m = ft_printf("ok\n");
	printf("my = %d\n", m);
	r = printf("%X\n", 42);
	printf("real = %d\n", r);
	m = ft_printf("%X\n", 42);
	printf("my = %d\n", m);
	r = printf("before %X after\n", 42);
	printf("real = %d\n", r);
	m = ft_printf("before %X after\n", 42);
	printf("my = %d\n", m);

*/	
/*
	printf("\033[1;41m|-------------------------| (Lancement du test LETTRE en cours...) |-------------------------|\033[0m\n");
	printf("\033[1;32m|-----| LE VRAI |-----|\033[0m\n");
	ft_printf("\033[1;31m|-----| LE NOTRE |-----|\033[0m\n");
	printf("{%d}\n", printf("\033[1;32mTest 1 => \033[0m|%05.c|", 0));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 1 => \033[0m|%05.c|", 0));
	printf("{%d}\n", printf("\033[1;32mTest 2 => \033[0m|%05.c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 2 => \033[0m|%05.c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 3 => \033[0m|%c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 3 => \033[0m|%c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 4 => \033[0m|%hhc|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 4 => \033[0m|%hhc|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 5 => \033[0m|%hc|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 5 => \033[0m|%hc|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 6 => \033[0m|%llc|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 6 => \033[0m|%llc|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 7 => \033[0m|%jc|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 7 => \033[0m|%jc|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 8 => \033[0m|%zc|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 8 => \033[0m|%zc|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 9 => \033[0m|%+c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 9 => \033[0m|%+c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 10 => \033[0m|%#c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 10 => \033[0m|%#c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 11 => \033[0m|%c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 11 => \033[0m|%c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 12 => \033[0m|%-c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 12 => \033[0m|%-c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 13 => \033[0m|%15c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 13 => \033[0m|%15c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 14 => \033[0m|%-15c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 14 => \033[0m|%-15c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 15 => \033[0m|%.2c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 15 => \033[0m|%.2c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 16 => \033[0m|% c|", 0));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 16 => \033[0m|% c|", 0));
	printf("{%d}\n", printf("\033[1;32mTest 17 => \033[0m|%c|", "coucou"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 17 => \033[0m|%c|", "coucou"));
	printf("{%d}\n", printf("\033[1;32mTest 18 => \033[0m|%05.c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 18 => \033[0m|%05.c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 19 => \033[0m|%015c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 19 => \033[0m|%015c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 20 => \033[0m|%-015c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 20 => \033[0m|%-015c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 21 => \033[0m|%-0c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 21 => \033[0m|%-0c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 22 => \033[0m|%.12c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 22 => \033[0m|%.12c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 23 => \033[0m|%.0c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 23 => \033[0m|%.0c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%-12.3c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 24 => \033[0m|%-12.3c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 25 => \033[0m|%-3.1c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 25 => \033[0m|%-3.1c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 26 => \033[0m|%12.1c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 26 => \033[0m|%12.1c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 27 => \033[0m|%3.1c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 27 => \033[0m|%3.1c|", '4'));
	printf("{%d}\n", printf("\033[1;32mTest 28 => \033[0m|%-c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 28 => \033[0m|%-c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 29 => \033[0m|%3c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 29 => \033[0m|%3c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 30 => \033[0m|%-3c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 30 => \033[0m|%-3c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 31 => \033[0m|%.2c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 31 => \033[0m|%.2c|", 'a'));
	printf("{%d}\n", printf("\033[1;32mTest 32 => \033[0m|%5.5c|", "N"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 32 => \033[0m|%5.5c|", "N"));
	printf("{%d}\n", printf("\033[1;32mTest 33 => \033[0m|%7.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 33 => \033[0m|%7.5c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 34 => \033[0m|%.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 34 => \033[0m|%.5c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 35 => \033[0m|%.15c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 35 => \033[0m|%.15c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 36 => \033[0m|%15c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 36 => \033[0m|%15c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 37 => \033[0m|%5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 37 => \033[0m|%5c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 38 => \033[0m|%-5.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 38 => \033[0m|%-5.5c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 39 => \033[0m|%-15.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 39 => \033[0m|%-15.5c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 40 => \033[0m|%-.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 40 => \033[0m|%-.5c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 41 => \033[0m|%-15c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 41 => \033[0m|%-15c|", "Number 42"));
	printf("{%d}\n", printf("\033[1;32mTest 42 => \033[0m|%c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 42 => \033[0m|%c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 43 => \033[0m|%-c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 43 => \033[0m|%-c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 44 => \033[0m|%5.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 44 => \033[0m|%5.5c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 45 => \033[0m|%15.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 45 => \033[0m|%15.5c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 46 => \033[0m|%.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 46 => \033[0m|%.5c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 47 => \033[0m|%15c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 47 => \033[0m|%15c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 48 => \033[0m|%-5.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 48 => \033[0m|%-5.5c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 49 => \033[0m|%-15.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 49 => \033[0m|%-15.5c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 50 => \033[0m|%-.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 50 => \033[0m|%-.5c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 51 => \033[0m|%-15c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 51 => \033[0m|%-15c|", NULL));
	printf("{%d}\n", printf("\033[1;32mTest 52 => \033[0m|%15c|", "bonjour"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 52 => \033[0m|%15c|", "bonjour"));
*/
}
