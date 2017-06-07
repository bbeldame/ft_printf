/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:41:39 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/07 20:40:05 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_p(va_list argl, t_modif *modi)
{
	uintmax_t		nb;
	int				nblen;

	modi->hexa = 1;
	nb = (uintmax_t)va_arg(argl, void*);
	nblen = get_uintlen(nb, BASE_10);
	modi->digit -= 2;
	if (modi->minus)
		LEN += get_strlen("0x");
	PLUS = PLUS == 1 ? 0 : 0;
	SPACE = SPACE == 1 ? 0 : 0;
	if (SHARP == 1 && nb > 0)
		LEN += get_charlen('0');
	if (DIGIT > nblen || ZERO)
	{
		apply_digits(modi, nblen);
	}
	if (PRECI > nblen)
		apply_preci(modi, nblen);
	ft_putnbr_base(nb, HEXA_MIN);
	if (!modi->minus)
	{
		LEN += get_strlen("0x");
		ft_putnbr_base(nb, HEXA_MIN);
	}
	LEN += get_uintlen(nb, HEXA_MIN);
	return (LEN);
}
