/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:45:10 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/09 17:25:18 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_countbits(wchar_t value)
{
	int		size;

	size = 0;
	while (value)
	{
		value >>= 1;
		size++;
	}
	return (size);
}
