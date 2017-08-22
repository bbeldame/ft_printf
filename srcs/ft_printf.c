/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:47:12 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/22 20:16:41 by msakwins         ###   ########.fr       */
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
	while (format[i])
	{
		init_all(&modi);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (0);
			if (ft_strchr("sSpdDioOuUxXcCb?", format[i]))
			{
				ret += handle(format[i], argl, &modi);
			}
			else
			{
				i = parse_flags(argl, format, i, &modi);
				if (modi.percent == 1)
					return (0);
				ret += search_format(argl, format[i], &modi);
			}
		}
		else
			ret += get_charlen(format[i]);
		i++;
	}
	return (ret);
}

int				parse_flags(va_list argl, const char *format,
					int i, t_modif *modi)
{
	search_flag(format, i, modi);
	i += (modi->flag > 0) ? modi->flag : 0;
	i += search_digit(argl, format, i, modi);
	if (format[i] == '*' || ft_isdigit(format[i]))
		i += search_digit(argl, format, i, modi);
	if (format[i] == '.')
	{
		i++;
		PERIOD = 1;
		i += search_period(argl, format, i, modi);
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
		ret = handle(l, argl, modi);
	else
	{
		ret += handle_bd(modi, l);
	}
	return (ret);
}

int				handle(char c, va_list argl, t_modif *modi)
{
	if (c == 'D' || c == 'O' || c == 'X' || c == 'U' || c == 'C')
		modi->cap = 1;
	if (c == 'd' || c == 'i' || c == 'D')
		return (handle_d(argl, modi));
	else if (c == 'o' || c == 'O')
		return (handle_o(argl, modi));
	else if (c == 'x' || c == 'X')
		return (handle_x(argl, modi));
	else if (c == 'u' || c == 'U')
		return (handle_u(argl, modi));
	else if (c == 'p')
		return (handle_p(argl, modi));
	else if (c == 'c' || c == 'C')
		return (handle_w(argl, modi));
	else if (c == 's' && modi->mod == 0)
		return (handle_s(argl, modi));
	else if (c == 'S' || (c == 's' && modi->mod))
		return (handle_ws(argl, modi));
	else if (c == 'b')
		return (handle_b(argl, modi));
	return (0);
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
