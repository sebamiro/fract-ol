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

static int	darker(int color, int y)
{
	int	r;
	int	g;
	int	b;
	
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color) & 0xFF;
	return (0 << 24 | (r - r / 2 + y * 3) << 16 | (g - g / 2 + y * 3) << 8 | (b - b / 2 + y * 3));
}

void	put_text(t_mlx *mlx, char c)
{
	mlx_string_put(mlx->mlx, mlx->win, 80, H - 16, 0x00EBE0ED, "Move: Arrows");
	mlx_string_put(mlx->mlx, mlx->win, 250, H - 16, 0x00EBE0ED, "Zoom: scroll up/down");
	mlx_string_put(mlx->mlx, mlx->win, 480, H - 16, 0x00EBE0ED, "Change patron: p");
	mlx_string_put(mlx->mlx, mlx->win, 680, H - 16, 0x00EBE0ED, "Reset: r");
	mlx_string_put(mlx->mlx, mlx->win, 800, H - 16, 0x00EBE0ED, "More/Less iterations: +/-");
	mlx_string_put(mlx->mlx, mlx->win, 1100, H - 16, 0x00EBE0ED, "Exit: esc");
	if (c == 'j')
		mlx_string_put(mlx->mlx, mlx->win, 20, 20, 0x00523B56, "Press: j");
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