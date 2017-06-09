/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:52:29 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 20:48:36 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		width_errors(t_modif *modi, int nblen)
{
	if (DIGIT > 0 || PRECI > 0)
	{
		DIGIT = DIGIT < nblen ? 0 : DIGIT;
		PRECI = PRECI < nblen ? 0 : PRECI;
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
	if (DIGIT && !PERIOD)
		DIGIT = DIGIT - slen;
	if (DIGIT && PERIOD)
	{
		DIGIT = DIGIT - slen;
	}
}

void		apply_flags(t_modif *modi)
{
	if (PLUS == 1 && SPACE == 1)
		SPACE = 0;
	if (PLUS == 1 && !NEG)
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
	if (DIGIT)
		LEN += padding(DIGIT, p);
}

void		apply_preci(t_modif *modi)
{
	if (PERIOD)
	{
		LEN += padding(PRECI, '0');
	}
}
