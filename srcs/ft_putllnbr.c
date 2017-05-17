/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:09:29 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/17 22:52:01 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putllnbr(intmax_t nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
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
