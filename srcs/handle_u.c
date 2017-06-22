/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/22 14:28:48 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			handle_u(va_list argl, t_modif *modi)
{
	int					ret;
	uintmax_t			nb;
	int					nblen;
	int					neg;

	ret = 0;
	neg = 0;
	nb = ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_10);
	PLUS = 0;
	SPACE = 0;
	if (SHARP == 1 && nb > 0)
		ret += get_charlen('0');
	if (period_zero(nb, modi))
	{
		ret += apply_digits(modi);
		return (ret);
	}
	if (DIGIT || PRECI)
		width_errors(modi, nblen);
	if (MINUS)
	{
		ret += minus_spec(modi, nb);
	}
	if (DIGIT > 0)
	{
		ret += apply_digits(modi);
	}
	if (PRECI > 0 && !MINUS)
		ret += apply_preci(modi);
	if (!MINUS)
		ft_putnbr_base(nb, BASE_10);
	ret += nblen;
	return (ret);

}
