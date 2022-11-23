/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:01:49 by smiro             #+#    #+#             */
/*   Updated: 2022/11/19 20:02:05 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

int	zoom(int key, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	t_value		*value;
	double		zoom;
	double		inter;

	if (key != 4 && key != 5)
		return (0);
	value = &fractol->value;
	mouse = init_complex(
			(double)x / (W / (value->max.x - value->min.x))
			+ value->min.x, (double)y / (H / (value->max.y
					- value->min.y)) * -1 + value->max.y);
	if (key == 4)
		zoom = 0.8;
	else
		zoom = 1.20;
	inter = 1.0 / zoom;
	value->min.x = interpolate(mouse.x, value->min.x, inter);
	value->min.y = interpolate(mouse.y, value->min.y, inter);
	value->max.x = interpolate(mouse.x, value->max.x, inter);
	value->max.y = interpolate(mouse.y, value->max.y, inter);
	zoom_color(value->color, fractol, zoom);
	draw(fractol);
	return (0);
}
