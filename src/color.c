/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:45:56 by smiro             #+#    #+#             */
/*   Updated: 2023/02/28 11:46:00 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mix_color(int color, int n)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	n *= 20;
	if(r < b && r < g)
		r += n;
	else if(b < g)
		b += n;
	else
		g += n;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
 if (b > 255)
		b = 255;
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	zoom_color(int color, t_fractol *fractol, int i)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				n;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if (i > 0)
		n = 5;
	else
		n = -5;
	if ((r > 0 && r <= 255 && n > 0) || (g == 0 && b > 0 && b <= 255 && n < 0))
	{
		r -= n;
		b += n;
	}
	else if (b > 0 || (r == 0 && n < 0))
	{
		b -= n;
		g += n;
	}
	fractol->value.color = (0 << 24 | r << 16 | g << 8 | b);
}

int	get_color(int n, t_fractol *fractol)
{
	if (n == -1 && fractol)
		return (0);
	if (fractol->value.rep == -1)
		return (darker(fractol->value.color, n));
	return ((0x00FF0000 >> n) ^ fractol->value.color);
}
