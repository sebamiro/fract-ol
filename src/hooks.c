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

#include "../includes/fractol.h"

int	close_program(t_fractol *vars)
{
	mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
	exit(0);
	return (0);
}

int	key_hook(int key, t_fractol *vars)
{
	if (key == 53)
		close_program(vars);
	else if (key >= 123 && key <= 126)
		move(key, vars);
	return (0);
}