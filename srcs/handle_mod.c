/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:25 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 21:45:47 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		diouflag(uintmax_t nb, t_modif *modi, size_t neg, char *base)
{
	size_t		len;
	size_t		nblen;

	len = 0;
	if (modi->flag || modi->preci || modi->digit)
	{
		nblen = ft_strlen(itoa_base(nb, base));
		if (neg == 0 && (modi->plus || modi->space))
			len += handflag(modi);
		if (neg && modi->plus)
			len += get_charlen('-');
		if (modi->minus)
			ft_putnbr_base(nb, base);
		if (modi->zero || modi->minus || modi->period || modi->digit)
			len += handle_mod(modi, neg, nblen);
		if (!modi->minus)
			ft_putnbr_base(nb, base);
	}
	return (len);
}

size_t		handle_mod(t_modif *modi, size_t neg, size_t nblen)
{
	size_t		len;
	size_t		negok;

	len = 0;
	negok = 0;
	if (modi->digit > modi->period && (modi->period > nblen))
		modi->digit -= modi->period - nblen;
	if (modi->digit && neg == 1)
		modi->digit -= neg;
	else if (modi->period > modi->digit && modi->digit)
		modi->digit = 0;
	if (modi->zero)
		len += flagzero(modi, neg, nblen, negok);
	if ((modi->digit && modi->digit - nblen > nblen)
			|| (modi->preci && modi->period > nblen))
		len += digitorpreci(modi, neg, nblen, negok);
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
		}
		len += padding(nblen, modi->digit, '0');
		modi->digit = 0;
	}
	return (len);
}

size_t		digitorpreci(t_modif *modi, size_t neg, size_t nblen, size_t negok)
{
	size_t		len;

	len = 0;
	if (modi->digit > 0 && modi->digit - nblen > nblen)
	{
		len += padding(nblen, modi->digit, ' ');
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
		len += padding(nblen, modi->period, '0');
	}
	return (len);
}

size_t		padding(size_t nblen, size_t dig, char p)
{
	size_t		len;

	len = 0;
	while (dig > nblen)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}