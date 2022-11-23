/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:37:56 by smiro             #+#    #+#             */
/*   Updated: 2022/11/20 16:37:59 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(int key, t_fractol *fractol)
{
	t_complex	m;

	m = init_complex(fabs(fractol->value.max.x - fractol->value.min.x) * 0.05,
			fabs(fractol->value.max.y - fractol->value.min.y) * 0.05);
	if (key == 123)
	{
		fractol->value.min.x -= m.x;
		fractol->value.max.x -= m.x;
	}
	else if (key == 124)
	{
		fractol->value.min.x += m.x;
		fractol->value.max.x += m.x;
	}
	else if (key == 125)
	{
		fractol->value.min.y += m.y;
		fractol->value.max.y += m.y;
	}
	else
	{
		fractol->value.min.y -= m.y;
		fractol->value.max.y -= m.y;
	}
	draw(fractol);
}

void	change_iterations(int key, t_fractol *fractol)
{
	if (key == 69)
		fractol->value.max_iterations += 5;
	else if (fractol->value.max_iterations > 5)
		fractol->value.max_iterations -= 5;
	draw(fractol);
}