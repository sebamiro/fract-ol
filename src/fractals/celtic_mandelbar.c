/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:25:50 by smiro             #+#    #+#             */
/*   Updated: 2022/11/23 16:35:16 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	celtic_mandelbar(t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_complex	z2;

	i = 0;
	z = init_complex(fractol->value.c.x, fractol->value.c.y);
	z2 = init_complex(z.x * z.x, z.y * z.y);
	while (i < fractol->value.max_iterations
		&& z2.x + z2.y < 4)
	{
		z = init_complex(fabs(z2.x - z2.y) + fractol->value.c.x,
				-2 * z.x * z.y + fractol->value.c.y);
		z2 = init_complex(z.x * z.x, z.y * z.y);
		i++;
	}
	if (i == fractol->value.max_iterations)
		return (-1);
	if (fractol->value.rep == -1)
		return (i);
	return ((z2.x + z2.y * fractol->value.patron)
		+ i * fractol->value.patron / 10);
}
