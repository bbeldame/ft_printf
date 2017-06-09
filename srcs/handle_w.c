/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:39:24 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 18:02:33 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_w(va_list argl, t_modif *modi)
{
	wchar_t			value;
	int				size;
	int				nblen;

	if (modi->mod == 2)
		modi->mod = 0;
	value = ulenght_mod(argl, modi);
	size = ft_countbits(value);
	nblen = size <= 7 ? 1 : size / 8;
	width_errors(modi, nblen);
	if (DIGIT > 0)
		apply_digits(modi);
	LEN += ft_putwchar(value, size);
	return (LEN);
}

int			handle_ws(va_list argl, t_modif *modi)
{
	wchar_t			*wstr;
	int				slen;

	slen = 0;
	wstr = va_arg(argl, wchar_t*);
	if (wstr == NULL)
	{
		LEN += get_strlen("(null)");
		return (LEN);
	}
	slen = get_wlen(wstr);
	if (DIGIT > slen)
	{
		DIGIT = DIGIT - slen;
		apply_digits(modi);
		LEN += ft_putwstr(wstr);
	}
	else
		LEN += ft_putwstr(wstr);
	return (LEN);
}
