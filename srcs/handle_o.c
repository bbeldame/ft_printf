/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:17:21 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/15 14:59:00 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_o(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	size_t				len;
	char				*base;
	size_t				nblen;

	len = 0;
	base = "01234567";
	nb = ulenght_mod(argl, modi);
	nblen = ft_strlen(itoa_base(nb, base));
	if (modi->sharp == 1 && nb > 0)
		len += get_charlen('0');
	if (modi->flag || modi->digit > nblen || modi->period > nblen)
		len += diouflag(nb, modi, 0, base);
	else
	{
		if (modi->preci && !modi->period)
			return (len);
		ft_putnbr_base(nb, base);
	}
	len += nblen;
	return (len);
}
