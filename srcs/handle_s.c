/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:40:54 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 18:49:28 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_s(va_list argl, t_modif *modi)
{
	char		*str;
	int			slen;
	int			nblen;

	slen = 0;
	nblen = 0;
	str = va_arg(argl, char *);
	str = str == NULL ? "(null)" : str;
	if (PERIOD || DIGIT)
	{
		slen = ft_strlen(str);
		nblen = PERIOD && PRECI < slen ? PRECI : slen;
		width_errs(modi, nblen);
		if (DIGIT)
		{
			apply_digits(modi);
		}
		if (PERIOD && PRECI < slen)
		{
			LEN += PRECI;
			ft_putnstr(str, PRECI);
		}
		if (!PRECI || PRECI > nblen)
		{
			ft_putstr(str);
			LEN += slen;
		}
	}
	else
		LEN += get_strlen(str);
	return (LEN);
}

size_t		paddingchar(size_t dig, char p)
{
	size_t		len;

	len = 0;
	while (dig)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}
