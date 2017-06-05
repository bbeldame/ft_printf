/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:17:21 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/05 20:08:33 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_o(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	int					len;
	int					nblen;

	len = 0;
	nb = ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_8);
	modi->plus = modi->plus ? 0 : 0;
	if (modi->sharp == 1 && nb > 0)
		len += get_charlen('0');
	if (modi->flag || modi->digit > nblen || modi->period > nblen)
		len += diouflag(nb, modi, 0, BASE_8);
	else
	{
		if (modi->preci && !modi->period)
			return (len);
		ft_putnbr_base(nb, BASE_8);
	}
	len += nblen;
	return (len);
}
