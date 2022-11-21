/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:04:24 by seba              #+#    #+#             */
/*   Updated: 2022/10/31 23:21:36 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printstr(char *str)
{
	int	i;
	int	temp;
	int	total;

	i = 0;
	total = 0;
	while (str[i])
	{
		temp = ft_putchar(str[i]);
		if (temp < 0)
		{
			free(str);
			return (-1);
		}
		total += temp;
		i++;
	}
	free(str);
	return (total);
}

int	ft_putnbr(int n)
{
	char	*str;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	str = ftitoa(n);
	if (!str)
		return (-1);
	return (printstr(str));
}

int	ft_putuint(unsigned int n)
{
	char	*str;

	str = ft_unsigned_itoa(n);
	if (!str)
		return (-1);
	return (printstr(str));
}
