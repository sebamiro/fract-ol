/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:33:26 by smiro             #+#    #+#             */
/*   Updated: 2022/11/19 16:33:28 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	init_complex(double x, double y)
{
	t_complex	n;

	n.x = x;
	n.y = y;
	return (n);
}

static int	(*get_function(char *name)) (t_fractol *fractol)
{
	int	(*function)(t_fractol *fractol);

	function = NULL;
	if (!ft_strncmp(name, "mandelbrot", 11))
		function = &mandelbrot;
	else if (!ft_strncmp(name, "julia", 6))
		function = &julia;
	else if (!ft_strncmp(name, "burning ship", 13))
		function = &burning_ship;
	else if (!ft_strncmp(name, "mandelbar", 10))
		function = &mandelbar;
	else if (!ft_strncmp(name, "perpendicular mandelbrot", 26))
		function = &perpendicular_mandelbrot;
	return (function);
}

void	set_value(t_fractol *fractol)
{
	fractol->value.max_iterations = 50;
	fractol->value.min = init_complex(-2.5, -1);
	fractol->value.max = init_complex(1, 1);
	zoom_color(0x00FF0000, fractol, -1);
	fractol->value.patron = 1;
}

static t_img	init_image(void	*mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx, W, H);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	return (img);
}

t_fractol	*init_window(void *mlx, char *set)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		exit(1);
	fractol->set = set;
	fractol->mlx.mlx = mlx;
	fractol->mlx.win = mlx_new_window(fractol->mlx.mlx, W, H, set);
	fractol->img = init_image(mlx);
	set_value(fractol);
	fractol->function = get_function(set);
	return (fractol);
}
