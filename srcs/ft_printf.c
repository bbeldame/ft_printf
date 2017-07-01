/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:47:12 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/01 16:58:59 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				parse(va_list argl, const char *format)
{
	int					i;
	int					ret;
	t_modif				modi;

	i = 0;
	ret = 0;
	init_all(&modi);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = parse_flags(format, i, &modi);
			if (modi.percent == 1)
				return (0);
			ret += search_format(argl, format[i], &modi);
			init_all(&modi);
		}
		else
			ret += get_charlen(format[i]);
		i++;
	}
	free_all(&modi);
	return (ret);
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

int				search_format(va_list argl, char l, t_modif *modi)
{
	int			ret;

	ret = 0;
	if (ft_strchr("sSpdDioOuUxXcCb?", l))
	{
		ret = handle(l, argl, modi);
	}
	else
	{
		ret += handle_bd(modi, l);
	}
	return (ret);
}

int				handle(char c, va_list argl, t_modif *modi)
{
	int			ret;

	ret = 0;
	if (c == 'D' || c == 'O' || c == 'X' || c == 'U' || c == 'C')
		modi->cap = 1;
	ret = (c == 'd' || c == 'i' || c == 'D') ? handle_d(argl, modi) : ret;
	ret = (c == 'o' || c == 'O') ? handle_o(argl, modi) : ret;
	ret = (c == 'x' || c == 'X') ? handle_x(argl, modi) : ret;
	ret = (c == 'u' || c == 'U') ? handle_u(argl, modi) : ret;
	ret = (c == 'p') ? handle_p(argl, modi) : ret;
	ret = (c == 'c' || c == 'C') ? handle_w(argl, modi) : ret;
	ret = (c == 's' && modi->mod == 0) ? handle_s(argl, modi) : ret;
	ret = (c == 'S' || (c == 's' && modi->mod)) ? handle_ws(argl, modi) : ret;
	ret = (c == 'b') ? handle_b(argl, modi) : ret;
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list				argl;
	int					ret;
	
	ret = 0;
	va_start(argl, format);
	ret = parse(argl, format);
	va_end(argl);
	return (ret);
}
