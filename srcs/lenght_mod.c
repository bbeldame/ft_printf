/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:47:02 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/15 13:24:06 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		lenght_mod(va_list argl, t_modif *modi)
{
	intmax_t nbr;

	nbr = va_arg(argl, intmax_t);
	if (modi->mod == 1 && modi->cap != 1)
		nbr = (short int)nbr;
	else if (modi->mod == 2 && modi->cap != 1)
		nbr = (char)nbr;
	else if (modi->mod == 3 || modi->cap == 1)
		nbr = (long int)nbr;
	else if (modi->mod == 4)
		nbr = (long long int)nbr;
	else if (modi->mod == 5)
		nbr = (intmax_t)nbr;
	else if (modi->mod == 6)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t		ulenght_mod(va_list argl, t_modif *modi)
{
	uintmax_t nbr;

	nbr = va_arg(argl, uintmax_t);
	if (modi->mod == 1 && modi->cap != 1)
		nbr = (unsigned short int)nbr;
	else if (modi->mod == 2 && modi->cap != 1)
		nbr = (unsigned char)nbr;
	else if (modi->mod == 3 || modi->cap == 1)
		nbr = (unsigned long int)nbr;
	else if (modi->mod == 4)
		nbr = (unsigned long long int)nbr;
	else if (modi->mod == 5)
		nbr = (uintmax_t)nbr;
	else if (modi->mod == 6)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
