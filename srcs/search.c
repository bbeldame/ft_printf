/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:05:55 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/15 16:48:13 by bbeldame         ###   ########.fr       */
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
	MOD = 0;
	if (format[i] == 'h')
	{
		MOD = 1;
		i++;
		if (format[i] == 'h')
			MOD = 2;
	}
	else if (format[i] == 'l')
	{
		MOD = 3;
		i++;
		if (format[i] == 'l')
			MOD = 4;
	}
	else if (format[i] == 'j')
		MOD = 5;
	else if (format[i] == 'z')
		MOD = 6;
}

void		search_flag(const char *format, int i, t_modif *modi)
{
	FLAG = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
			format[i] == '+' || format[i] == ' ')
	{
		if (format[i] == '#')
			SHARP = 1;
		else if (format[i] == '0')
			ZERO = (MINUS) ? 0 : 1;
		else if (format[i] == '-')
		{
			MINUS = 1;
			ZERO = 0;
		}
		else if (format[i] == '+')
			PLUS = 1;
		else if (format[i] == ' ')
			SPACE = 1;
		i++;
		FLAG++;
	}
}

int			search_digit(const char *format, int i, t_modif *modi)
{
	char	*str;
	int		len;

	DIGIT = 0;
	if (!ft_isdigit(format[i]))
		return (0);
	DIGIT = ft_atoi(format + i);
	str = ft_itoa(DIGIT);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			search_period(const char *format, int i, t_modif *modi)
{
	char	*str;
	int		len;

	PRECI = 0;
	if (!ft_isdigit(format[i]))
		return (0);
	PRECI = ft_atoi(format + i);
	str = ft_itoa(PRECI);
	len = ft_strlen(str);
	free(str);
	return (len);
}
