/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handletype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:37:09 by seba              #+#    #+#             */
/*   Updated: 2022/10/29 13:28:49 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handlechar(va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	return (write(1, &c, 1));
}

int	handlenbr(va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexnbr(va_arg(ap, unsigned int), c));
	return (-1);
}

int	handlestr(va_list ap)
{
	char	*str;
	size_t	i;
	int		temp;
	int		total;

	total = 0;
	i = 0;
	str = va_arg(ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		temp = ft_putchar(str[i]);
		if (temp < 0)
			return (-1);
		total += temp;
		i++;
	}
	return (total);
}

int	handleptr(va_list ap)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	return (ft_putptr(n));
}
