/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:13:47 by seba              #+#    #+#             */
/*   Updated: 2022/10/29 13:31:18 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	findtype(va_list ap, char c)
{
	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
		return (handlechar(ap));
	else if (c == 'd' || c == 'i' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (handlenbr(ap, c));
	else if (c == 's')
		return (handlestr(ap));
	else if (c == 'p')
		return (handleptr(ap));
	return (-1);
}

int	ft_putctype(const char *s, va_list ap)
{
	size_t	i;
	int		total;
	int		temp;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			temp = findtype(ap, s[i]);
		}
		else
			temp = ft_putchar(s[i]);
		if (temp < 0)
			return (-1);
		total += temp;
		i++;
	}
	return (total);
}
