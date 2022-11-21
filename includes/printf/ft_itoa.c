/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftatoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:46:44 by smiro             #+#    #+#             */
/*   Updated: 2022/10/31 23:22:16 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unlen(unsigned int n)
{
	int	total;

	total = 1;
	while (n > 9)
	{
		total++;
		n = n / 10;
	}
	return (total);
}

static int	nlen(int n)
{
	int	total;

	total = 1;
	if (n < 0)
	{
		total++;
		n = -n;
	}
	while (n > 9)
	{
		total++;
		n = n / 10;
	}
	return (total);
}

char	*ftitoa(int n)
{
	char	*res;
	int		len;

	len = nlen(n);
	res = malloc (1 * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0 && len - 1 >= 0)
	{
		res[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (res);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		len;

	len = unlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n >= 0 && len - 1 >= 0)
	{
		res[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (res);
}
