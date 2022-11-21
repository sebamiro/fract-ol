/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:06:31 by seba              #+#    #+#             */
/*   Updated: 2022/10/29 13:30:58 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptrlen(uintptr_t ptr)
{
	int	total;

	total = 1;
	while (ptr >= 16)
	{
		ptr = ptr / 16;
		total++;
	}
	return (total);
}

static int	printptr(uintptr_t ptr)
{
	int	total;

	total = 0;
	if (ptr >= 16)
	{
		total += printptr(ptr / 16);
		total += printptr(ptr % 16);
	}
	else if (ptr < 10)
		total += ft_putchar((ptr + '0'));
	else
		total += ft_putchar(ptr - 10 + 'a');
	return (total);
}

int	ft_putptr(unsigned long long ptr)
{
	int	total;
	int	temp;

	total = 0;
	if (ptr == 0)
		return (write(1, "0x0", 3));
	temp = write(1, "0x", 2);
	if (temp < 0)
		return (-1);
	total += temp;
	temp = printptr(ptr);
	if (temp < 0)
		return (-1);
	total += temp;
	if (total != ptrlen(ptr) + 2)
		return (-1);
	return (total);
}
