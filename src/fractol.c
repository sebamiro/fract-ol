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

#include "../includes/fractol.h"
#include <stdio.h>

static void	start(int ac, char **av)
{
	void		*mlx;
	t_fractol	*fractol;

	mlx = mlx_init();
	fractol = init_window(mlx, av[1]);
	if (fractol->set[0] == 'j')
		fractol->value.k = init_complex(ft_atof(av[2]), ft_atof(av[3]));
	draw(fractol);
	if (ac)
		mlx_hook(fractol->mlx.win, 17, 0, close_program, fractol);
	mlx_hook(fractol->mlx.win, 2, 0, key_hook, fractol);
	mlx_hook(fractol->mlx.win, 4, 0, zoom, fractol);
	mlx_loop(fractol->mlx.mlx);
}

int	main(int ac, char **av)
{
	ft_check(ac, av);
	start(ac, av);
	return (0);
}
