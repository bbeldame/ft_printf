/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 22:01:48 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Handle some bad behavior
** Bad format
*/

int			handle_bd(t_modif *modi, char c)
{
	if (MINUS)
	{
		LEN += get_charlen(c);
	}
	if (DIGIT > 0)
	{
		if (ZERO)
			LEN += padding(DIGIT - 1, '0');
		else
			LEN += padding(DIGIT - 1, ' ');
	}
	if (!MINUS)
	{
		LEN += get_charlen(c);
	}
	return (LEN);
}
