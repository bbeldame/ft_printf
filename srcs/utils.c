/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:23:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/05/31 20:26:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_all(t_modif *modi)
{
	modi->mod = 0;
	modi->flag = 0;
	modi->plus = 0;
	modi->minus = 0;
	modi->sharp = 0;
	modi->space = 0;
	modi->zero = 0;
	modi->preci = 0;
	modi->digit = 0;
	modi->period = 0;
	modi->percent = 0;
	modi->cap = 0;
	modi->hexa = 0;
}
