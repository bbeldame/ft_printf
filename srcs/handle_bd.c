/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/22 14:25:20 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Handle some bad behavior
** Bad format
*/

int			handle_bd(t_modif *modi, char c)
{
	int		ret;

	ret = 0;
	if (MINUS)
	{
		ret += get_charlen(c);
	}
	if (DIGIT > 0)
	{
		if (ZERO)
			ret += padding(DIGIT - 1, '0');
		else
			ret += padding(DIGIT - 1, ' ');
	}
	if (!MINUS)
	{
		ret += get_charlen(c);
	}
	return (ret);
}
