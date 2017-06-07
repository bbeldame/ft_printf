/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:56:57 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/07 20:47:21 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_d(va_list argl, t_modif *modi)
{
	intmax_t		nb;
	int				nblen;
	int				negatif;

	negatif = 0;
	nb = lenght_mod(argl, modi);
	NEG = nb < 0 ? 1 : 0;
	nb = NEG == 1 ? -nb : nb;
	nblen = get_uintlen(nb, BASE_10);
	if (PLUS || SPACE)
	{
		apply_flags(modi);
	}
	if ((ZERO == 1) && NEG == 1)
	{
		LEN += get_charlen('-');
		negatif = 1;
	}
	if (DIGIT > nblen || ZERO == 1)
	{
		apply_digits(modi, nblen);
	}
	if (NEG == 1 && !negatif && PERIOD == 1)
	{
		LEN += get_charlen('-');
		negatif = 1;
	}
	if (PERIOD == 1 && PRECI > nblen)
	{
		apply_preci(modi, nblen);
	}
	if (NEG == 1 && !ZERO && !PERIOD)
		LEN += get_charlen('-');
	ft_putnbr_base(nb, BASE_10);
	LEN += nblen;
	return (LEN);
}
