/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:56:57 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/05 21:22:01 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				handle_d(va_list argl, t_modif *modi)
{
	intmax_t		nb;
	int				neg;
	int				nblen;

	nb = lenght_mod(argl, modi);
	neg = nb < 0 ? 1 : 0;
	nb = neg == 1 ? -nb : nb;
	nblen = get_uintlen(nb, BASE_10);
	if (modi->flag || modi->period > nblen || modi->digit > nblen)
		LEN += diouflag(nb, modi, neg, BASE_10);
	else
	{
		if (modi->preci && !modi->period)
			return (LEN);
		if (neg)
			LEN += get_charlen('-');
		ft_putllnbr(nb);
	}
	LEN += nblen;
	return (LEN);
}
