/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:41:33 by msakwins          #+#    #+#             */
/*   Updated: 2017/04/26 19:57:17 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putnbr_base(uintmax_t nb, char *base)
{
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
