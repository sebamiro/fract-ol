/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:56:24 by smiro             #+#    #+#             */
/*   Updated: 2023/03/09 11:56:26 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	sierpinsky(t_fractol *fractol)
{
	static t_complex	a;
	static t_complex	b;
	static t_complex	c;
	static t_complex	d;
	static int background = 0;

	a = init_complex((double)W / 5, H - ((double)H / 4));
	b = init_complex(W - a.x, a.y);
	c = init_complex((double)W / 2, ((double)H / 5));
	d = init_complex((double)W / 2, (double)H / 2);

	int r;

	if (!background)
	{
		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++)
				pixel_put(&fractol->img, x, y, 0x00f5b3f9);
		background = 1;
		mlx_put_image_to_window(fractol->mlx.mlx,
			fractol->mlx.win, fractol->img.img, 0, 0);
		return ;
	}

	for (int i = 0; i < fractol->value.max_iterations; i++)
	{
		r = rand() % 3;
		if (r == 0)
			d = init_complex((a.x + d.x) / 2, (a.y + d.y) / 2);
		else if (r == 1)
			d = init_complex((b.x + d.x) / 2, (b.y + d.y) / 2);
		else
			d = init_complex((c.x + d.x) / 2, (c.y + d.y) / 2);
		pixel_put(&fractol->img, d.x, d.y, 0x00403240);
	}
	mlx_put_image_to_window(fractol->mlx.mlx,
		fractol->mlx.win, fractol->img.img, 0, 0);
}
