/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:23:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/05/18 00:24:19 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_all(t_modif *modi)
{
	modi->sharp = 0;
	modi->zero = 0;
	modi->minus = 0;
	modi->plus = 0;
	modi->space = 0;
}
