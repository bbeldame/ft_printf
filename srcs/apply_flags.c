/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:52:29 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/11 19:19:08 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		width_errors(t_modif *modi, int nblen)
{
	if (PRECI > 0)
		ZERO = 0;
	if ((PLUS && !NEG) || SPACE)
		DIGIT = DIGIT - 1;
	if (DIGIT > 0 || PRECI > 0)
	{
		DIGIT = DIGIT <= nblen ? 0 : DIGIT;
		PRECI = PRECI <= nblen ? 0 : PRECI;
	}
	if (DIGIT > 0 && PRECI == 0)
	{
		DIGIT = DIGIT - nblen;
	}
	else if (PRECI > 0 && DIGIT == 0)
	{
		PRECI = PRECI - nblen;
	}
	else if (DIGIT > nblen && PRECI > nblen)
	{
		DIGIT = DIGIT - PRECI;
		PRECI = PRECI - nblen;
	}
	else if (DIGIT > nblen && PRECI < nblen)
		DIGIT = DIGIT - nblen;
	else if (DIGIT < nblen && PRECI > nblen)
		PRECI = PRECI - nblen;
}

void		width_errs(t_modif *modi, int slen)
{
	if (DIGIT > 0 && DIGIT < slen)
		DIGIT = 0;
	if (DIGIT > 0 && !PERIOD)
		DIGIT = DIGIT - slen;
	if (DIGIT > 0 && PERIOD > 0)
		DIGIT = DIGIT - slen;
}

void		apply_flags(t_modif *modi)
{
	if (PLUS == 1 && SPACE == 1)
		SPACE = 0;
	if (PLUS == 1 && !NEG && PRECI == 0)
		LEN += get_charlen('+');
	if (SPACE == 1 && !NEG)
		LEN += get_charlen(' ');
}

void		apply_digits(t_modif *modi)
{
	char	p;

	DIGIT -= NEG == 1 ? 1 : 0;
	if (MINUS == 1 && ZERO == 1)
		ZERO = 0;
	p = ZERO == 1 ? '0' : ' ';
	if (DIGIT > 0)
		LEN += padding(DIGIT, p);
}

void		apply_preci(t_modif *modi)
{
	if (PLUS && !NEG)
		LEN += get_charlen('+');
	if (PERIOD)
	{
		LEN += padding(PRECI, '0');
	}
}
