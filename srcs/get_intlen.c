/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:12:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 22:54:50 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_uintlen(uintmax_t nb, char *base)
{
	int		len;
	char	*str;

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

int			get_clen(int size)
{
	int		clen;

	clen = 0;

	clen = size <= 7 ? 1 : clen;
	clen = (size > 7 && size <= 11) ? 2 : clen;
	clen = (size > 11 && size <= 16) ? 3 : clen;
	clen = (size > 16 && size <= 32) ? 4 : clen;
	return (clen);
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
