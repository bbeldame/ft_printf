/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:25 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/05 20:53:42 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			diouflag(uintmax_t nb, t_modif *modi, int neg, char *base)
{
	int			nblen;
	int			negok;

	negok = 0;
	if (modi->flag || modi->preci || modi->digit)
	{
		nblen = get_uintlen(nb, base);
		if (modi->plus || modi->space)
			apply_flags(modi, neg);
		if (neg && !negok && (modi->plus || modi->space || modi->minus)
			&& !modi->period && (negok = 1) == 1)
			LEN += get_charlen('-');
		if (modi->minus > 0)
		{
			LEN += padding(nblen, modi->period, '0');
			ft_putnbr_base(nb, base);
		}
		LEN += (ZERO && !PERIOD) ? flagzero(modi, neg, nblen, negok) : 0;
		if (modi->minus || modi->period || modi->digit)
			LEN += handle_mod(modi, neg, nblen, negok);
		if (modi->minus == 0 && !modi->hexa)
			ft_putnbr_base(nb, base);
	}
	return (LEN);
}

int			handle_mod(t_modif *modi, int neg, int  nblen, int negok)
{
	int			len;

	len = 0;
	if (modi->digit > modi->period && (modi->period > nblen))
	{
		modi->digit -= modi->period - nblen;
	}
	if (modi->digit && neg == 1)
	{
		modi->digit -= neg;
	}
	else if (modi->period > modi->digit && modi->digit)
	{
		modi->digit = 0;
	}
	if ((modi->digit >= nblen)
			|| (modi->preci && modi->period > nblen))
	{
		len += digitorpreci(modi, neg, nblen, negok);
	}
	return (len);
}

int			flagzero(t_modif *modi, int neg, int nblen, int negok)
{
	int			len;

	len = 0;
	if (modi->space)
		modi->digit -= 1;
	if (modi->zero)
	{
		if (neg && !negok)
		{
			len += get_charlen('-');
			negok = 1;
		}
		modi->digit += (negok && modi->plus) ? 1 : 0;
		modi->digit += (negok && modi->space) ? 1 : 0;
		len += padding(nblen, modi->digit - modi->plus - negok, '0');
		modi->digit = 0;
	}
	return (len);
}

int			digitorpreci(t_modif *modi, int neg, int nblen, int negok)
{
	int			len;

	len = 0;
	if (modi->digit > nblen && modi->period > nblen &&
		modi->digit < modi->period)
		modi->digit = 0;
	if (modi->digit >= nblen)
	{
		len += padding(nblen, modi->digit - modi->plus - modi->space, ' ');
		len += (neg && (modi->plus || modi->space)) ? get_charlen(' ') : 0;
		if (neg && !negok && (negok = 1) == 1)
			len += get_charlen('-');
	}
	if (modi->preci == 1 && modi->period > nblen)
	{
		if (neg && !negok && (negok = 1) == 1)
			len += get_charlen('-');
		if (!modi->minus)
		{
			len += (modi->plus && !negok) ? get_charlen('+') : 0;
			len += padding(nblen, modi->period - modi->minus, '0');
		}
	}
	return (len);
}

int			padding(int nblen, int dig, char p)
{
	int			len;

	len = 0;
	while (dig > nblen)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}
