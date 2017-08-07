/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:25 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/22 14:29:10 by bbeldame         ###   ########.fr       */
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

int			minus_spec(t_modif *modi, uintmax_t nb)
{
	int			ret;

	ret = 0;
	ret += apply_preci(modi);
	ft_putnbr_base(nb, BASE_10);
	return (ret);
}
