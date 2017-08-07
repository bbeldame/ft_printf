/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:09:29 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/15 17:19:59 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putllnbr(intmax_t nb)
{
	if (nb == LONG_MIN)
		ft_putstr("9223372036854775808");
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putllnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putllnbr(nb / 10);
		ft_putllnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
