/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:45:10 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/29 15:34:31 by msakwins         ###   ########.fr       */
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
