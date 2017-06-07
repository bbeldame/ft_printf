/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:25 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/07 20:07:39 by msakwins         ###   ########.fr       */
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
