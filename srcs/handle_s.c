/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:40:54 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/07 20:40:44 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_period_or_digit(t_modif *modi, char *str)
{
	int		ret;
	int		slen;
	int		nblen;

	ret = 0;
	slen = 0;
	nblen = 0;
	slen = ft_strlen(str);
	nblen = PERIOD && PRECI < slen ? PRECI : slen;
	width_errs(modi, nblen);
	if (DIGIT && !MINUS)
		ret += apply_digits(modi);
	if (PERIOD == 1 && PRECI >= 0 && PRECI < slen)
	{
		ret += PRECI;
		ft_putnstr(str, PRECI);
	}
	else
	{
		ft_putstr(str);
		ret += slen;
	}
	if (DIGIT && MINUS)
		ret += apply_digits(modi);
	return (ret);
}

size_t		handle_s(va_list argl, t_modif *modi)
{
	int			ret;
	char		*str;

	ret = 0;
	str = va_arg(argl, char *);
	str = str == NULL ? "(null)" : str;
	if (PERIOD || DIGIT)
		ret += handle_period_or_digit(modi, str);
	else
		ret += get_strlen(str);
	return (ret);
}

size_t		paddingchar(size_t dig, char p)
{
	size_t		len;

	len = 0;
	while (dig)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}
