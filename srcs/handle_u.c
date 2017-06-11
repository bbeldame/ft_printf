/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/11 21:05:13 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_u(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	int					len;
	int					nblen;
	int					neg;

	neg = 0;
	len = 0;
	nb = ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_10);
	PLUS = PLUS == 1 ? 0 : 0;
	SPACE = SPACE == 1 ? 0 : 0;
	if (SHARP == 1 && nb > 0)
		LEN += get_charlen('0');
	if (period_zero(nb, modi))
	{
		apply_digits(modi);
		return (LEN);
	}
	if (DIGIT || PRECI)
		width_errors(modi, nblen);
	if (MINUS)
	{
		minus_spec(modi, nb);
	}
	if (DIGIT > 0)
	{
		apply_digits(modi);
	}
	if (PRECI > 0 && !MINUS)
		apply_preci(modi);
	if (!MINUS)
		ft_putnbr_base(nb, BASE_10);
	LEN += nblen;
	return (LEN);

}
