/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:37:12 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/07 20:11:13 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conv_ex(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*itoa_base(uintmax_t value, char *base)
{
	int				i;
	char			*str;
	uintmax_t		tmp;
	unsigned int	baselen;

	i = 0;
	tmp = value;
	baselen = ft_strlen(base);
	while (tmp >= baselen)
	{
		tmp = tmp / baselen;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 20))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % baselen;
		str[i] = conv_ex(tmp);
		value /= baselen;
		i--;
	}
	return (str);
}
