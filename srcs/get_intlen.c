/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:12:47 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/22 19:53:22 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_uintlen(uintmax_t nb, char *base)
{
	int					len;
	unsigned int		baselen;

	len = 1;
	baselen = ft_strlen(base);
	while (nb >= baselen)
	{
		nb = nb / baselen;
		len++;
	}
	return (len);
}

int			get_charlen(char c)
{
	write(1, &c, 1);
	return (1);
}

int			get_strlen(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int			get_clen(int size)
{
	if (size <= 7)
		return (1);
	else if (size > 7 && size <= 11)
		return (2);
	else if (size > 11 && size < 17)
		return (3);
	else if (size > 16 && size <= 32)
		return (4);
	return (0);
}

int			get_wstrlen(wchar_t *wstr)
{
	int		size;
	int		wlen;

	wlen = 0;
	size = 0;
	while (*wstr != '\0')
	{
		size = ft_countbits(*wstr);
		wlen += get_clen(size);
		wstr++;
	}
	return (wlen);
}
