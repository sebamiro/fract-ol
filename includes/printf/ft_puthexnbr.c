/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:31:21 by seba              #+#    #+#             */
/*   Updated: 2022/10/29 13:33:08 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexnbr(unsigned int n, char x)
{
	char	*nums;
	int		total;
	int		temp;

	total = 0;
	nums = "0123456789abcdef";
	if (n >= 16)
	{
		temp = ft_puthexnbr((n / 16), x);
		if (temp < 0)
			return (-1);
		total += temp;
		temp = ft_puthexnbr((n % 16), x);
		if (temp < 0)
			return (-1);
		total += temp;
	}
	else
	{
		if (x == 'X' && n > 9)
			return (ft_putchar(nums[n] - 32));
		else
			return (ft_putchar(nums[n]));
	}
	return (total);
}
