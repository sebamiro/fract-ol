/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:10:28 by smiro             #+#    #+#             */
/*   Updated: 2022/11/24 12:10:30 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	darker(int color, int y)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color) & 0xFF;
	return (0 << 24 | (r - r / 2 + y * 3) << 16 | (g - g / 2 + y * 3) << 8 | (b - b / 2 + y * 3));
}

void	put_text(t_fractol *fractol)
{
	int	n = W / 7;
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, n, H - 16, 0x00EBE0ED, "Move: Arrows");
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, n * 2, H - 16, 0x00EBE0ED, "Zoom: scroll up/down");
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, n * 3, H - 16, 0x00EBE0ED, "Change patron: p");
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, n * 4, H - 16, 0x00EBE0ED, "Reset: r");
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, n * 5, H - 16, 0x00EBE0ED, "More/Less iterations: +/-");
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, n * 6, H - 16, 0x00EBE0ED, "Exit: esc");
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, 10, H - 16, 0x00333333, fractol->set);
	if (fractol->set[0] == 'j')
		mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, 20, 20, 0x00523B56, "Press: j");
}

void	controls(t_fractol *fractol)
{
	int	x;
	int	y;

	y = H - 1;
	while (y > H - 40)
	{
			x = 0;
			while (x < W)
			{
				pixel_put(&fractol->img, x, y, darker(fractol->value.color, H - y));
				x++;
			}
			y--;
	}
}
