/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:01:53 by smiro             #+#    #+#             */
/*   Updated: 2022/11/13 15:04:59 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_complex
{
	double	x;
	double	y;
}							t_complex;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}								t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}								t_img;

typedef struct s_value
{
	int			max_iterations;
	t_complex	min;
	t_complex	max;
	t_complex	pixel;
	t_complex	k;
	t_complex	c;
	int			start_y;
	int			end_y;
	int			color;
	int			patron;
	int			rep;
}								t_value;

typedef struct s_fractol
{
	char	*set;
	int		(*function)(struct s_fractol *fractol);
	t_mlx	mlx;
	t_img	img;
	t_value	value;
	int		sierpinsky;
}								t_fractol;

# define TH 6
# define W 1928
# define H 1080

#endif
