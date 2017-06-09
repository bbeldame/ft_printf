/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:47:12 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 16:16:45 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				parse(va_list argl, const char *format, t_modif *modi)
{
	int					i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = parse_flags(format, i, modi);
			if (modi->percent == 1)
				return (0);
			search_format(argl, format[i], modi);
		}
		else
			LEN += get_charlen(format[i]);
		i++;
	}
	return (LEN);
}

int				parse_flags(const char *format, int i, t_modif *modi)
{
	search_flag(format, i, modi);
	i += (modi->flag > 0) ? modi->flag : 0;
	i += search_digit(format, i, modi);
	if (format[i] == '.')
	{
		i++;
		PERIOD = 1;
		i += search_period(format, i, modi);
	}
	search_mod(format, i, modi);
	i += (modi->mod > 0) ? 1 : 0;
	if (modi->mod == 2 || modi->mod == 4)
		i++;
	if (format[i] == '\0')
	{
		modi->percent = search_percent(format, i, modi);
		if (modi->percent)
			return (0);
	}
	return (i);
}

void			search_format(va_list argl, char l, t_modif *modi)
{
//	if (l == '%')
//	{
//		LEN += (l == '%') ? get_charlen('%') : 0;
//	}
	if (ft_strchr("sSpdDioOuUxXcCb?", l))
	{
		handle(l, argl, modi);
	}
	else
	{
		LEN += get_charlen(l);
		if (modi->digit > 0)
		{
			LEN += padding(DIGIT, ' ');
		}
	}
}

void			handle(char c, va_list argl, t_modif *modi)
{
	if (c == 'D' || c == 'O' || c == 'X' || c == 'U')
		modi->cap = 1;
	LEN = (c == 'd' || c == 'i' || c == 'D') ? handle_d(argl, modi) : LEN;
	LEN = (c == 'o' || c == 'O') ? handle_o(argl, modi) : LEN;
	LEN = (c == 'x' || c == 'X') ? handle_x(argl, modi) : LEN;
	LEN = (c == 'u' || c == 'U') ? handle_u(argl, modi) : LEN;
	LEN = (c == 'p') ? handle_p(argl, modi) : LEN;
	LEN = (c == 'c' || c == 'C') ? handle_w(argl, modi) : LEN;
	LEN = (c == 's' && modi->mod == 0) ? handle_s(argl, modi) : LEN;
	LEN = (c == 'S' || (c == 's' && modi->mod)) ? handle_ws(argl, modi) : LEN;
	LEN = (c == 'b') ? handle_b(argl, modi) : LEN;
}

int				ft_printf(const char *format, ...)
{
	va_list				argl;
	t_modif				*modi;
	int					len;
	
	len = 0;
	if (!(modi = malloc(sizeof(t_modif))))
		return (0);
	init_all(modi);
	va_start(argl, format);
	LEN = parse(argl, format, modi);
	len = LEN;
	init_all(modi);
	free(modi);
	va_end(argl);
	return (len);
}
