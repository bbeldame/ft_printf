/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:56:57 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 21:46:11 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			handle_d(va_list argl, t_modif *modi)
{
	size_t			len;
	intmax_t		nb;
	size_t			neg;
	char			*base;
	size_t			nblen;

	len = 0;
	base = "0123456789";
	nb = lenght_mod(argl, modi);
	neg = nb < 0 ? 1 : 0;
	nb = neg == 1 ? -nb : nb;
	nblen = ft_strlen(ft_itoa(nb));
	if (modi->flag || modi->period > nblen || modi->digit > nblen)
		len += diouflag(nb, modi, neg, base);
	else
	{
		if (modi->preci && !modi->period)
			return (len);
		if (neg && nb != LONG_MIN)
			len += get_charlen('-');
		ft_putnbr(nb);
	}
	len += ft_strlen(ft_itoa(nb));
	return (len);
}

size_t			handflag(t_modif *modi)
{
	size_t			len;

	len = 0;
	len += (modi->plus) ? get_charlen('+') : 0;
	len += (modi->space) ? get_charlen(' ') : 0;
	return (len);
}
