/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:05:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/29 15:51:23 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			search_percent(const char *format, int i, t_modif *modi)
{
	modi->percent = 0;
	if (format[i] == '\0')
		return (1);
	return (0);
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
	init_all(modi);
	modi->flag = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
			format[i] == '+' || format[i] == ' ')
	{
		if (format[i] == '#')
			modi->sharp = 1;
		else if (format[i] == '0')
			modi->zero = (modi->minus) ? 0 : 1;
		else if (format[i] == '-')
		{
			modi->minus = 1;
			modi->zero = 0;
		}
		else if (format[i] == '+')
			modi->plus = 1;
		else if (format[i] == ' ')
		{
			modi->space = 1;
		}
		i++;
		modi->flag++;
	}
}

int			search_digit(const char *format, int i, t_modif *modi)
{
	char	*str;
	int		len;

	modi->digit = 0;
	if (!ft_isdigit(format[i]))
		return (0);
	modi->digit = ft_atoi(format + i);
	str = ft_itoa(modi->digit);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			search_period(const char *format, int i, t_modif *modi)
{
	char	*str;
	int		len;

	modi->period = 0;
	if (!ft_isdigit(format[i]))
		return (0);
	modi->period = ft_atoi(format + i);
	str = ft_itoa(modi->period);
	len = ft_strlen(str);
	free(str);
	return (len);
}
