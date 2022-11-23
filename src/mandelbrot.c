/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:28:36 by smiro             #+#    #+#             */
/*   Updated: 2022/11/19 16:28:40 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_fractol *fractol)
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
		z = init_complex(z2.x - z2.y + fractol->value.c.x,
				2 * z.x * z.y + fractol->value.c.y);
		z2 = init_complex(z.x * z.x, z.y * z.y);
		i++;
	}
	if (i == fractol->value.max_iterations)
		return (-1);
	return ((z2.x + z2.y * fractol->value.patron) + i / 10);
}
