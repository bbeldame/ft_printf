/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:56:57 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 22:21:28 by bbeldame         ###   ########.fr       */
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
	if (period_zero(nb, modi))
		return (LEN);
	if (PRECI > 0 || DIGIT > 0)
		width_errors(modi, nblen);
	if (MINUS)
	{
		if (NEG)
			LEN += get_charlen('-');
		ft_putnbr_base(nb, BASE_10);
	}
	if (PLUS || SPACE)
	{
		apply_flags(modi);
	}
	if ((ZERO == 1) && NEG == 1)
	{
		LEN += get_charlen('-');
		negatif = 1;
	}
	if (DIGIT > 0)
	{
		apply_digits(modi);
	}
	if (NEG == 1 && !negatif && PRECI > 0)
	{
		LEN += get_charlen('-');
		negatif = 1;
	}
	if (PRECI > 0)
	{
		apply_preci(modi);
	}
	if (NEG == 1 && !ZERO && !PRECI && !MINUS)
		LEN += get_charlen('-');
	if (!MINUS)
		ft_putnbr_base(nb, BASE_10);
	LEN += nblen;
	return (LEN);
}
