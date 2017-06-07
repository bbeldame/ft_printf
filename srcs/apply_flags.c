/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:52:29 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/07 20:37:13 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		apply_flags(t_modif *modi)
{
	if (PLUS == 1 && SPACE == 1)
		SPACE = 0;
	if (PLUS == 1 && !NEG)
		LEN += get_charlen('+');
	if (SPACE == 1 && !NEG)
		LEN += get_charlen(' ');
}

void		apply_digits(t_modif *modi, int nblen)
{
	char	p;

	if (DIGIT)
		DIGIT = DIGIT - nblen;
	if (DIGIT > nblen && PRECI > nblen)
		DIGIT = DIGIT - (PRECI - nblen);
	DIGIT -= NEG == 1 ? 1 : 0;
	if (MINUS == 1 && ZERO == 1)
		ZERO = 0;
	p = ZERO == 1 ? '0' : ' ';
	if (DIGIT)
		LEN += padding(DIGIT, p);
}

void		apply_preci(t_modif *modi, int nblen)
{
	if (PERIOD)
	{
		PRECI = PRECI - nblen;
		LEN += padding(PRECI, '0');
	}
}
