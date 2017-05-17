/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/17 18:36:35 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_u(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	size_t				len;
	size_t				nblen;
	size_t				neg;
	char				*base;

	neg = 0;
	len = 0;
	base = "0123456789";
	nb = ulenght_mod(argl, modi);
	nblen = ft_strlen(itoa_base(nb, base));
	modi->plus = modi->plus == 1 ? 0 : 0;
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
