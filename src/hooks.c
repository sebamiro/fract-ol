/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:07:06 by smiro             #+#    #+#             */
/*   Updated: 2022/11/19 18:07:09 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_fractol *vars)
{
	mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
	exit(0);
}

int	key_hook(int key, t_fractol *vars)
{
	if (key == 53)
		close_program(vars);
	else if (key >= 123 && key <= 126)
		move(key, vars);
	else if (key == 15)
		set_value(vars);
	else if (key == 69 || key == 78 || key == 40 || key == 37)
		change_iterations(key, vars);
	else if (key == 35)
		vars->value.rep *= -1;
	else if (key == 38)
		change_julia(vars);
	else if (key >= 18 && key <= 29)
		change_set(key, vars);
	else if (vars->sierpinsky)
	{
		if (key == 49)
			sierpinsky(vars);
		return 0;
	}
	else
		return (0);
	draw(vars);
	return (0);
}
