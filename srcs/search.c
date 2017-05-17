/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:05:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 21:42:01 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			search_percent(char l)
{
	int			len;

	len = 0;
	if (l == '%')
		len += get_charlen('%');
	return (len);
}

void		search_mod(const char *format, int i, t_modif *modi)
{
	modi->mod = 0;
	if (format[i] == 'h')
	{
		modi->mod = 1;
		i++;
		if (format[i] == 'h')
			modi->mod = 2;
	}
	else if (format[i] == 'l')
	{
		modi->mod = 3;
		i++;
		if (format[i] == 'l')
			modi->mod = 4;
	}
	else if (format[i] == 'j')
		modi->mod = 5;
	else if (format[i] == 'z')
		modi->mod = 6;
}

void		search_flag(const char *format, int i, t_modif *modi)
{
	modi->flag = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
			format[i] == '+' || format[i] == ' ')
	{
		if (format[i] == '#')
			modi->sharp = 1;
		else if (format[i] == '0')
			modi->zero = 1;
		else if (format[i] == '-')
			modi->minus = 1;
		else if (format[i] == '+')
			modi->plus = 1;
		else if (format[i] == ' ')
			modi->space = 1;
		i++;
		modi->flag++;
	}
}

void		search_digit(const char *format, int i, t_modif *modi)
{
	char	*str;
	int		y;

	y = 0;
	modi->digit = 0;
	str = malloc(sizeof(char) * 5 + 1);
	if (str)
	{
		if (ft_isdigit(format[i]))
		{
			str[y] = format[i];
			y++;
			i++;
			if (ft_isdigit(format[i]))
				str[y] = format[i];
			modi->digit = ft_atoi(str);
		}
		free(str);
	}
}

int			search_period(const char *format, int i, t_modif *modi)
{
	char	*str;
	int		y;
	int		stlen;

	y = 0;
	stlen = 0;
	modi->period = 0;
	if (!(str = malloc(sizeof(char) * 5 + 1)))
		return (0);
	if (!ft_isdigit(format[i]))
		return (modi->period = 0);
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
		{
			str[y] = format[i];
			y++;
			i++;
		}
		modi->period = ft_atoi(str);
		stlen = ft_strlen(str);
		free(str);
	}
	return (stlen);
}
