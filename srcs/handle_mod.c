/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:25 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/11 21:04:04 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			padding(int dig, char p)
{
	int			len;

	len = 0;
	while (dig)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}

void		minus_spec(t_modif *modi, uintmax_t nb)
{
	apply_preci(modi);
	ft_putnbr_base(nb, BASE_10);
}
