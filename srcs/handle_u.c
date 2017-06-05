/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/05 20:10:38 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_u(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	int					len;
	int					nblen;
	int					neg;

	neg = 0;
	len = 0;
	nb = ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_10);
	modi->plus = modi->plus == 1 ? 0 : 0;
	modi->space = modi->space ? 0 : 0;
	if (modi->flag || modi->digit > nblen || modi->period > nblen)
		len += diouflag(nb, modi, 0, BASE_10);
	else
	{
		if (modi->preci && !modi->period)
			return (len);
		ft_putnbr_base(nb, BASE_10);
	}
	len += nblen;
	return (len);
}
