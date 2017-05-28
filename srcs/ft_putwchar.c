/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:33:42 by msakwins          #+#    #+#             */
/*   Updated: 2017/05/28 20:02:55 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putwchar(wchar_t value, int size)
{
	int				len;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	unsigned char	octet;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	octet = '\0';
	if (size <= 7)
	{
		octet = value;
		write(1, &octet, 1);
		len = 1;
	}
	else if (size <= 11)
		len = ft_putwchar11(mask1, octet, value);
	else if (size <= 16)
		len = ft_putwchar16(mask2, octet, value);
	else
		len = ft_putwchar32(mask3, octet, value);
	return (len);
}

int		ft_putwchar11(unsigned int mask1, unsigned char octet, wchar_t value)
{
	unsigned int	v;
	unsigned char	o2;
	unsigned char	o1;

	v = value;
	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
	return (2);
}

int		ft_putwchar16(unsigned int mask2, unsigned char octet, wchar_t value)
{
	unsigned int	v;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	v = value;
	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
	return (3);
}

int		ft_putwchar32(unsigned int mask3, unsigned char octet, wchar_t value)
{
	unsigned int	v;
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	v = value;
	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
	return (4);
}
