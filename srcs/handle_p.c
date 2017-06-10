/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:41:39 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/10 20:19:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_p(va_list argl, t_modif *modi)
{
	uintmax_t		nb;
	int				nblen;

	modi->hexa = 1;
	nb = (uintmax_t)va_arg(argl, void*);
	nblen = get_uintlen(nb, HEXA_MIN);
	DIGIT -= 2;
	PLUS = 0;
	SPACE = 0;
	if (period_zero(nb, modi))
		return (LEN + get_strlen("0x"));
	if (PRECI || DIGIT)
		width_errors(modi, nblen);
	if (SHARP == 1 && nb > 0)
		LEN += get_charlen('0');
	if (MINUS || ZERO)
	{
		LEN += get_strlen("0x");
		ft_putnbr_base(nb, HEXA_MIN);
	}
	if (DIGIT > 0)
	{
		apply_digits(modi);
	}
	if (!MINUS && !ZERO)
		LEN += get_strlen("0x");
	if (PRECI > 0)
		apply_preci(modi);
	if (!MINUS && !ZERO)
		ft_putnbr_base(nb, HEXA_MIN);
	LEN += get_uintlen(nb, HEXA_MIN);
	return (LEN);
}
