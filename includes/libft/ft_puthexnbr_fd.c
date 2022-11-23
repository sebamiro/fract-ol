/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:07 by smiro             #+#    #+#             */
/*   Updated: 2022/11/23 11:27:39 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexnbr_fd(unsigned int n, char x, int fd)
{
	char	*nums;

	nums = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthexnbr_fd((n / 16), x, fd);
		ft_puthexnbr_fd((n % 16), x, fd);
	}
	else
	{
		if (x == 'X' && n > 9)
			ft_putchar_fd(nums[n] - 32, fd);
		else
			ft_putchar_fd(nums[n], fd);
	}
}
