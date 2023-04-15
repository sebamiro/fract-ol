/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:08:02 by smiro             #+#    #+#             */
/*   Updated: 2022/11/13 16:08:05 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start(char **av)
{
	void		*mlx;
	t_fractol	*fractol;

	mlx = mlx_init();
	fractol = init_window(mlx, av[1]);
	fractol->value.k = init_complex(-0.285, -0.656);
	if (fractol->sierpinsky)
		sierpinsky(fractol);
	else
		draw(fractol);
	mlx_hook(fractol->mlx.win, 17, 0, close_program, fractol);
	mlx_hook(fractol->mlx.win, 2, 0, key_hook, fractol);
	mlx_hook(fractol->mlx.win, 4, 0, zoom, fractol);
	mlx_loop(fractol->mlx.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 1)
		ft_check(ac, av);
	start(av);
	return (0);
}
