/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:12:02 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/22 16:13:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_putwstr(wchar_t *wstr)
{
	static int	len;
	int			size;

	len = 0;
	while (*wstr != '\0')
	{
		size = ft_countbits(*wstr);
		ft_putwchar(*wstr, size);
		len = (size / 4) + len;
		wstr++;
	}
	return (len);
}

int			get_preciw(wchar_t *wstr, int n)
{
	int			size;
	int			clen;
	int			wlen;

	size = 0;
	clen = 0;
	wlen = 0;
	while (n >= clen)
	{
		size = ft_countbits(*wstr);
		clen = get_clen(size);
		n -= clen;
		wlen += clen;
		wstr++;
	}
	return (wlen);
}

int			ft_putwnstr(wchar_t *wstr, int n)
{
	int			size;
	int			clen;
	int			wlen;

	size = 0;
	clen = 0;
	wlen = 0;
	while (n >= clen)
	{
		size = ft_countbits(*wstr);
		clen = get_clen(size);
		ft_putwchar(*wstr, size);
		n -= clen;
		wlen += clen;
		wstr++;
	}
	return (wlen);
}
