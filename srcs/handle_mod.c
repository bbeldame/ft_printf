/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:25 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/28 20:16:11 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		diouflag(uintmax_t nb, t_modif *modi, size_t neg, char *base)
{
	size_t		len;
	size_t		nblen;
	size_t		negok;

	len = 0;
	negok = 0;
	if (modi->flag || modi->preci || modi->digit)
	{
		nblen = ft_strlen(itoa_base(nb, base));
		if (neg == 0 && (modi->plus || modi->space))
		{
			len += handflag(modi);
		}
		if (neg && !negok && (modi->plus || modi->space || modi->minus)
			&& (negok = 1) == 1)
		{
			len += get_charlen('-');
		}
		if (modi->minus > 0)
		{
			len += padding(nblen, modi->period, '0');
			ft_putnbr_base(nb, base);
		}
		if (modi->zero && !modi->period)
		{
			len += flagzero(modi, neg, nblen, negok);
		}
		if (modi->minus || modi->period || modi->digit)
		{
			len += handle_mod(modi, neg, nblen, negok);
		}
		if (modi->minus == 0)
			ft_putnbr_base(nb, base);
	}
	return (len);
}

size_t		handle_mod(t_modif *modi, size_t neg, size_t nblen, size_t negok)
{
	size_t		len;

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

size_t		flagzero(t_modif *modi, size_t neg, size_t nblen, size_t negok)
{
	size_t		len;

	len = 0;
	if (modi->zero)
	{
		if (neg && !negok)
		{
			len += get_charlen('-');
			negok = 1;
			modi->digit -= 1;
		}
		modi->digit += (negok && modi->plus) ? 1 : 0;
		len += padding(nblen, modi->digit - modi->plus - negok, '0');
		modi->digit = 0;
	}
	return (len);
}

size_t		digitorpreci(t_modif *modi, size_t neg, size_t nblen, size_t negok)
{
	size_t		len;

	len = 0;
	if (modi->digit > nblen && modi->period > nblen && modi->digit < modi->period)
		modi->digit = 0;
	if (modi->digit >= nblen)
	{
		len += padding(nblen, modi->digit - modi->plus, ' ');
		if (neg && !negok)
		{
			len += get_charlen('-');
			negok = 1;
		}
	}
	if (modi->preci == 1 && modi->period > nblen)
	{
		if (neg && !negok)
		{
			len += get_charlen('-');
			negok = 1;
		}
		if (!modi->minus)
			len += padding(nblen, modi->period - modi->minus, '0');
	}
	return (len);
}

size_t		padding(size_t nblen, int dig, char p)
{
	size_t		len;

	len = 0;
	while (dig > (int)nblen)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}
