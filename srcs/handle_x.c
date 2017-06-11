/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:26:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/11 19:03:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Ca ca timeout pas toujours
*/

int				handle_x(va_list argl, t_modif *modi)
{
	size_t				len;
	uintmax_t			nb;
	int					nblen;
	char				*base;

	len = 0;
	nb = ulenght_mod(argl, modi);
	if (modi->mod == 2 && modi->cap == 1)
		nb = (unsigned char)to_unsigned_char_modulo(nb);
	if (CAP == 1 && MOD == 0)
	{
		nb = (unsigned int)nb;
	}
	base = modi->cap == 1 ? HEXA_CAP : HEXA_MIN;
	nblen = get_uintlen(nb, base);
	if (modi->sharp && nb > 0)
		LEN += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
	PLUS = PLUS == 1 ? 0 : 0;
	SPACE = SPACE == 1 ? 0 : 0;
	if (period_zero(nb, modi))
	{
		apply_digits(modi);
		return (LEN);
	}
	if (DIGIT || PRECI)
		width_errors(modi, nblen);
	if (DIGIT > 0)
	{
		apply_digits(modi);
	}
	if (PRECI > 0)
		apply_preci(modi);
	ft_putnbr_base(nb, base);
	LEN += nblen;
	return (LEN);
}

/*
** Ca ca timeout toujours mais ca regle tout
*/

/*
int				handle_x(va_list argl, t_modif *modi)
{
	size_t				len;
	uintmax_t			nb;
	int					nblen;
	char				*base;

	len = 0;
	nb = ulenght_mod(argl, modi);
	if (modi->mod == 2 && modi->cap == 1)
		nb = (unsigned char)to_unsigned_char_modulo(nb);
	base = modi->cap == 1 ? HEXA_CAP : HEXA_MIN;
	nblen = get_uintlen(nb, base);
	PLUS = 0;
	SPACE = 0;
	DIGIT -= (SHARP && nb > 0) ? 2 : 0;
	if (period_zero(nb, modi))
	{
		apply_digits(modi);
		return (LEN);
	}
	if (DIGIT || PRECI)
	{
		width_errors(modi, nblen);
	}
	if (MINUS)
	{
		if (SHARP && nb > 0)
			LEN += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
		ft_putnbr_base(nb, base);
		apply_digits(modi);
	}
	if (PRECI > 0)
	{
		apply_digits(modi);
		if (SHARP && nb > 0)
			LEN += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
		apply_preci(modi);
	}
	if (!MINUS)
	{
		if (DIGIT && !PRECI)
			apply_digits(modi);
		if (SHARP && nb > 0 && !PRECI)
			LEN += (modi->cap) ? get_strlen("0X") : get_strlen("0x");
		ft_putnbr_base(nb, base);
	}
	LEN += nblen;
	return (LEN);
}
*/

uintmax_t		to_unsigned_char_modulo(uintmax_t nbr)
{
	uintmax_t new_nbr;

	new_nbr = nbr;
	while (new_nbr >= 256)
		new_nbr -= 256;
	return (new_nbr);
}
