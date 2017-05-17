/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:37:38 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 21:40:31 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			parse(va_list argl, const char *format)
{
	t_modif				*modi;
	size_t				len;
	int					i;

	len = 0;
	i = 0;
	modi = malloc(sizeof(t_modif));
	if (modi == NULL)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = parse_flags(format, i, modi);
			len += search_format(argl, format[i], modi);
		}
		else
			len += get_charlen(format[i]);
		i++;
	}
	return (len);
}

int				parse_flags(const char *format, int i, t_modif *modi)
{
	search_flag(format, i, modi);
	i += (modi->flag > 0) ? modi->flag : 0;
	search_digit(format, i, modi);
	i += (modi->digit > 0) ? 1 : 0;
	i += (modi->digit > 9) ? 1 : 0;
	search_mod(format, i, modi);
	i += (modi->mod > 0) ? 1 : 0;
	if (modi->mod == 2 || modi->mod == 4)
		i++;
	if (format[i] == '.')
	{
		i++;
		modi->preci = 1;
		if (modi->preci == 1)
		{
			i += search_period(format, i, modi);
		}
	}
	return (i);
}

size_t			search_format(va_list argl, char l, t_modif *modi)
{
	char				*letter;
	size_t				len;

	len = 0;
	if (l == '%')
	{
		len = (l == '%') ? get_charlen('%') : len;
		return (len);
	}
	letter = ft_strchr("sSpdDioOuUxXcC?", l);
	len = (*letter == l) ? handle(l, argl, modi) : get_charlen(l);
	return (len);
}

size_t			handle(char c, va_list argl, t_modif *modi)
{
	size_t				len;

	len = 0;
	if (c == 'D' || c == 'O' || c == 'X' || c == 'U')
		modi->cap = 1;
	len = (c == 'd' || c == 'i' || c == 'D') ? handle_d(argl, modi) : len;
	len = (c == 'o' || c == 'O') ? handle_o(argl, modi) : len;
	len = (c == 'x' || c == 'X') ? handle_x(argl, modi) : len;
	len = (c == 'u' || c == 'U') ? handle_u(argl, modi) : len;
	len = (c == 'p') ? handle_p(argl, modi) : len;
	len = (c == 'c' || c == 'C') ? handle_w(argl, modi) : len;
	len = (c == 's' && modi->mod == 0) ? handle_s(argl, modi) : len;
	len = (c == 'S' || (c == 's' && modi->mod)) ? handle_ws(argl, modi) : len;
	return (len);
}

size_t			ft_printf(const char *format, ...)
{
	va_list				argl;
	size_t				len;

	len = 0;
	va_start(argl, format);
	len = parse(argl, format);
	va_end(argl);
	return (len);
}