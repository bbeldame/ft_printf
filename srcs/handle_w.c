/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:39:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/23 23:22:28 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_w_minus(t_modif *modi, wchar_t value)
{
	int ret;

	ret = 0;
	ret += apply_preci(modi);
	if (!modi->cap && !modi->mod)
		ret += get_charlen(value);
	else
		ret += ft_putwchar(value);
	return (ret);
}

int			handle_w(va_list argl, t_modif *modi)
{
	int				ret;
	wchar_t			value;
	int				size;

	ret = 0;
	MOD = (MOD == 2) ? 0 : MOD;
	value = ulenght_mod(argl, modi);
	size = ft_countbits(value);
	if (PRECI || PERIOD || FLAG || DIGIT)
	{
		width_errors(modi, size);
		if (MINUS)
			ret += handle_w_minus(modi, value);
		ret += (DIGIT > 0) ? apply_digits(modi) : 0;
	}
	if (!MINUS)
	{
		if (size <= 1 && !CAP && !MOD)
			ret += get_charlen(value);
		else if (!modi->cap && !modi->mod)
			ret += get_charlen(value);
		else
			ret += ft_putwchar(value);
	}
	return (ret);
}

static int	ws_flags(t_modif *modi, wchar_t *wstr, int slen)
{
	int ret;
	int wlen;

	ret = 0;
	wlen = 0;
	if (PERIOD == 1 && PRECI < slen && PRECI > 0)
		wlen = get_preciw(wstr, PRECI);
	else
		wlen = slen;
	if (PERIOD == 1 && PRECI == 0)
		wlen = 0;
	if (PERIOD == 0 && MINUS)
		ret += ft_putwstr(wstr);
	if (DIGIT > wlen)
	{
		DIGIT = DIGIT - wlen;
		ret += apply_digits(modi);
		if (PERIOD == 0 && !MINUS)
			ret += ft_putwstr(wstr);
	}
	if (PERIOD == 1 && PRECI > 0 && PRECI <= slen)
	{
		ret += ft_putwnstr(wstr, PRECI);
	}
	return (ret);
}

int			handle_ws(va_list argl, t_modif *modi)
{
	int				ret;
	wchar_t			*wstr;
	int				slen;

	ret = 0;
	slen = 0;
	wstr = va_arg(argl, wchar_t*);
	if (wstr == NULL)
	{
		ret += get_strlen("(null)");
		return (ret);
	}
	slen = get_wstrlen(wstr);
	if (PERIOD == 1 || DIGIT > 0)
		ret += ws_flags(modi, wstr, slen);
	else
		ret += ft_putwstr(wstr);
	return (ret);
}
