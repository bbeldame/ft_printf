/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:12:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/01 20:51:39 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_uintlen(uintmax_t nb, char *base)
{
	int		len;
	char	*str;

	ft_putnbr_base(nb, base);
	str = itoa_base(nb, base);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			get_charlen(char c)
{
	ft_putchar(c);
	return (1);
}

int			get_strlen(char *str)
{
	int		len;

	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}
