/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:52:29 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/05 21:22:03 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		apply_flags(t_modif *modi, int neg)
{
	if (PLUS == 1 && SPACE == 1)
		SPACE = 0;
	if (PLUS == 1 && (!PRECI || MINUS))
		LEN += get_charlen('+');
	if (SPACE == 1 && !neg)
		LEN += get_charlen(' ');
}
