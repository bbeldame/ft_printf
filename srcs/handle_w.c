/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:39:24 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 21:41:01 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_w(va_list argl, t_modif *modi)
{
	wchar_t			value;
	int				len;
	size_t			size;

	len = 0;
	value = ulenght_mod(argl, modi);
	if (modi->digit > 0)
		len += padding(1, modi->digit, ' ');
	size = ft_countbits(value);
	len += ft_putwchar(value, size);
	return (len);
}

size_t		handle_ws(va_list argl, t_modif *modi)
{
	wchar_t			*wstr;
	size_t			len;
	size_t			slen;

	len = 0;
	slen = 0;
	wstr = va_arg(argl, wchar_t*);
	if (wstr == NULL)
	{
		len = get_strlen("(null)");
		return (len);
	}
	if (modi->period || modi->digit)
		len = ft_putwstr(wstr);
	else
		len = ft_putwstr(wstr);
	return (len);
}
