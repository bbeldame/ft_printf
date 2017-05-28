/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:41:39 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/28 20:07:53 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_p(va_list argl, t_modif *modi)
{
	uintmax_t		nb;
	size_t			len;
	size_t			nblen;

	len = 0;
	nb = (uintmax_t)va_arg(argl, void*);
	nblen = ft_strlen(ft_itoa(nb));
	if (modi->digit > 0)
		{
			len += get_charlen(' ');
			modi->digit--;
		}
	len += get_strlen("0x");
	len = get_uintlen(nb, HEXA_MIN) + len;
	return (len);
}
