/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:41:39 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/28 23:02:29 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_p(va_list argl, t_modif *modi)
{
	uintmax_t		nb;
	size_t			len;
	size_t			nblen;

	len = 0;
	modi->hexa = 1;
	nb = (uintmax_t)va_arg(argl, void*);
	nblen = get_uintlen(nb, "0123456789");
	modi->digit -= 2;
	if (modi->flag || modi->period > nblen || modi->digit > nblen)
		len += diouflag(nb, modi, 0, HEXA_MIN);
	len += get_strlen("0x");
	ft_putnbr_base(nb, HEXA_MIN);
	len += get_uintlen(nb, HEXA_MIN);
	return (len);
}
