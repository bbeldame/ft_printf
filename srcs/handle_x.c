/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:26:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/29 15:50:54 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_x(va_list argl, t_modif *modi)
{
	size_t				len;
	uintmax_t			nb;
	size_t				nblen;
	char				*base;

	len = 0;
	nb = ulenght_mod(argl, modi);
	if (modi->mod == 2 && modi->cap == 1)
		nb = (unsigned char)to_unsigned_char_modulo(nb);
	base = modi->cap == 1 ? HEXA_CAP : HEXA_MIN;
	nblen = get_uintlen(nb, base);
	if (modi->flag == 1 && nb > 0 && modi->cap != 1 && !modi->zero)
		len += get_strlen("0x");
	if (modi->flag == 1 && nb > 0 && modi->cap == 1 && !modi->zero)
		len += get_strlen("0X");
	if (modi->flag || modi->digit > nblen || modi->period > nblen)
		len += diouflag(nb, modi, 0, base);
	else
	{
		if (modi->preci && !modi->period)
			return (len);
		ft_putnbr_base(nb, base);
	}
	len += nblen;
	return (len);
}

uintmax_t		to_unsigned_char_modulo(uintmax_t nbr)
{
	uintmax_t new_nbr;

	new_nbr = nbr;
	while (new_nbr >= 256)
		new_nbr -= 256;
	return (new_nbr);
}
