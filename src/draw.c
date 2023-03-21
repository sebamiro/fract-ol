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

static void	*draw_segment(t_fractol *fractol)
{
	double	x;
	double	y;

	y = fractol->value.start_y;
	while (y < fractol->value.end_y)
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
	return (NULL);
}

void	draw(t_fractol *fractol)
{
	pthread_t	thread[TH];
	t_fractol	fractols[TH];
	int	i;

	i = 0;
	fractol->value.pixel = init_complex(
			(fractol->value.max.x - fractol->value.min.x) / (W - 1),
			(fractol->value.max.y - fractol->value.min.y) / (H - 1));
	while (i < TH)
	{
		fractol->value.start_y = i * (H / TH);
		fractol->value.end_y = (i + 1) * (H / TH);
		fractols[i] = *fractol;
		if (pthread_create(&thread[i], NULL, (void *(*)(void *))draw_segment, &fractols[i]))
			exit(2);
		i++;
	}
	while (i-- > 0)
		pthread_join(thread[i], NULL);
	controls(fractol);
	mlx_put_image_to_window(fractol->mlx.mlx,
		fractol->mlx.win, fractol->img.img, 0, 0);
	put_text(fractol);
}
