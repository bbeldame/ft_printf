/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:26:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 20:51:06 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_x(va_list argl, t_modif *modi)
{
	size_t				len;
	uintmax_t			nb;
	size_t				nblen;
	char				*base;

	len = 0;
	nb = ulenght_mod(argl, modi);
	base = modi->cap == 1 ? HEXA_CAP : HEXA_MIN;
	nblen = ft_strlen(itoa_base(nb, base));
	if (modi->flag == 1 && nb > 0 && modi->cap != 1)
		len += get_strlen("0x");
	if (modi->flag == 1 && nb > 0 && modi->cap == 1)
		len += get_strlen("0X");
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
