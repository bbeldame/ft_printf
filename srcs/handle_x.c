/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:26:47 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/23 22:02:19 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		handle_no_minus(t_modif *modi, char *base, uintmax_t nb)
{
	int ret;

	ret = 0;
	if (SHARP && nb > 0 && !PRECI && ZERO)
		ret += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
	if (DIGIT && !PRECI)
		ret += apply_digits(modi);
	if (SHARP && nb > 0 && !PRECI && !ZERO)
		ret += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
	ft_putnbr_base(nb, base);
	return (ret);
}

static int		handle_flags(t_modif *modi, int nblen, char *base, uintmax_t nb)
{
	int ret;

	ret = 0;
	if (DIGIT || PRECI)
		width_errors(modi, nblen);
	if (MINUS)
	{
		if (SHARP && nb > 0)
			ret += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
		ft_putnbr_base(nb, base);
		ret += apply_digits(modi);
	}
	if (PRECI > 0)
	{
		ret += apply_digits(modi);
		if (SHARP && nb > 0)
			ret += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
		ret += apply_preci(modi);
	}
	if (!MINUS)
		ret += handle_no_minus(modi, base, nb);
	ret += nblen;
	return (ret);
}

int				handle_x(va_list argl, t_modif *modi)
{
	int					ret;
	size_t				len;
	uintmax_t			nb;
	int					nblen;
	char				*base;

	ret = 0;
	len = 0;
	if (!CAP && !MOD)
		nb = va_arg(argl, unsigned int);
	else
		nb = ulenght_mod(argl, modi);
	if (MOD == 2 && CAP == 1)
		nb = (unsigned char)to_unsigned_char_modulo(nb);
	if (CAP && !MOD)
		nb = (unsigned int)nb;
	base = CAP == 1 ? HEXA_CAP : HEXA_MIN;
	nblen = get_uintlen(nb, base);
	if (FLAG || PERIOD || PRECI || DIGIT || !MINUS)
	{
		PLUS = 0;
		SPACE = 0;
		DIGIT -= (SHARP && nb > 0) ? 2 : 0;
		if (period_zero(nb, modi))
		{
			ret += apply_digits(modi);
			return (ret);
		}
		ret += handle_flags(modi, nblen, base, nb);
	}
	return (ret);
}

uintmax_t		to_unsigned_char_modulo(uintmax_t nbr)
{
	uintmax_t new_nbr;

	new_nbr = nbr;
	while (new_nbr >= 256)
		new_nbr -= 256;
	return (new_nbr);
}
