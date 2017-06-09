/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:12:02 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/09 17:09:28 by msakwins         ###   ########.fr       */
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
