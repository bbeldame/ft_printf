/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:26:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/05 20:09:49 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				handle_x(va_list argl, t_modif *modi)
{
	size_t				len;
	uintmax_t			nb;
	int					nblen;
	char				*base;

	len = 0;
	nb = ulenght_mod(argl, modi);
	if (modi->mod == 2 && modi->cap == 1)
		nb = (unsigned char)to_unsigned_char_modulo(nb);
	base = modi->cap == 1 ? HEXA_CAP : HEXA_MIN;
	nblen = get_uintlen(nb, base);
	if (modi->sharp && nb > 0)
		len += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
	modi->digit -= (modi->sharp && (modi->zero || modi->minus)) ? 2 : 0;
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
