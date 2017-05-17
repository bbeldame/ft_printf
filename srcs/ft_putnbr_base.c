/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:35:04 by msakwins          #+#    #+#             */
/*   Updated: 2017/04/01 17:45:29 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putnbr_base(uintmax_t nb, char *base)
{
	if (nb >= ft_strlen(base))
	{
		putnbr_base(nb / ft_strlen(base), base);
		putnbr_base(nb % ft_strlen(base), base);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}
