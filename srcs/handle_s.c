/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:40:54 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/29 15:50:08 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_s(va_list argl, t_modif *modi)
{
	char		*str;
	size_t		len;
	size_t		slen;

	len = 0;
	slen = 0;
	str = va_arg(argl, char *);
	str = str == NULL ? "(null)" : str;
	if (modi->period || modi->digit)
	{
		slen = ft_strlen(str);
		slen = modi->period < slen ? modi->period : slen;
		modi->digit -= modi->digit < slen ? modi->digit : 0;
		len += modi->digit ? paddingchar(modi->digit - slen, ' ') : 0;
		if (modi->period)
		{
			if (modi->period > slen)
				return (len += get_strlen(str));
			ft_putnstr(str, modi->period);
			len += modi->period;
		}
	}
	else
		len = get_strlen(str);
	return (len);
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
