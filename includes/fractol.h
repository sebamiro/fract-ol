/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:24:08 by smiro             #+#    #+#             */
/*   Updated: 2022/11/13 17:24:13 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "defines.h"

t_complex	init_complex(double x, double y);
t_fractol	*init_window(void *mlx, char *set);
int			close_program(t_fractol *vars);
int			key_hook(int key, t_fractol *vars);
int			zoom(int key, int x, int y, t_fractol *fractol);
void		move(int key, t_fractol *fractol);
void		draw(t_fractol *fractol);
void		pixel_put(t_img *img, int x, int y, int color);
void		controls(t_fractol *fractol);
void		put_text(t_mlx *mlx);
void		zoom_color(int color, t_fractol *fractol, int i);
void		set_value(t_fractol *fractol);
void		change_iterations(int key, t_fractol *fractol);
int			mandelbrot(t_fractol *fractol);
int			julia(t_fractol *fractol);
int			burning_ship(t_fractol *fractol);
int			mandelbar(t_fractol *fractol);
int			perpendicular_mandelbrot(t_fractol *fractol);
int			celtic_mandelbrot(t_fractol *fractol);
int			celtic_mandelbar(t_fractol *fractol);
int			perpendicular_celtic(t_fractol *fractol);
int			heart(t_fractol *fractol);
int			buffalo(t_fractol *fractol);
float		ft_atof(char *n);
void		ft_check(int ac, char **av);

#endif