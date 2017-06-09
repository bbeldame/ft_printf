/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:17:21 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 21:34:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_o(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	int					nblen;

	nb = ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_8);
	PLUS = PLUS == 1 ? 0 : 0;
	SPACE = SPACE == 1 ? 0 : 0;
	if (SHARP == 1 && nb > 0)
		LEN += get_charlen('0');
	if (period_zero(nb, modi))
		return (LEN);
	if (PRECI || DIGIT)
		width_errors(modi, nblen);
	if (DIGIT > 0)
	{
		apply_digits(modi);
	}
	if (PRECI > 0)
		apply_preci(modi);
	ft_putnbr_base(nb, BASE_8);
	LEN += nblen;
	return (LEN);
}
