/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:32:16 by smiro             #+#    #+#             */
/*   Updated: 2022/11/19 18:32:29 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
	return ((0x00FF0000 >> n) ^ fractol->value.color);
}

void	draw(t_fractol *fractol)
{
	double	x;
	double	y;

	fractol->value.pixel = init_complex(
			(fractol->value.max.x - fractol->value.min.x) / (W - 1),
			(fractol->value.max.y - fractol->value.min.y) / (H - 1));
	y = 0;
	while (y < H)
	{
		fractol->value.c.y = fractol->value.min.y + y * fractol->value.pixel.y;
		x = 0;
		while (x < W)
		{
			fractol->value.c.x = (fractol->value.min.x
					+ x * fractol->value.pixel.x);
			pixel_put(&fractol->img, x, y,
				get_color(fractol->function(fractol), fractol));
			x++;
		}
		y++;
	}
	controls(fractol);
	mlx_put_image_to_window(fractol->mlx.mlx,
		fractol->mlx.win, fractol->img.img, 0, 0);
	put_text(&fractol->mlx);
}
