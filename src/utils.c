/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:14:14 by smiro             #+#    #+#             */
/*   Updated: 2022/11/13 17:14:34 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	ft_atof(char *n)
{
	int		i;
	int		j;
	float	nb;
	int		m;

	i = 0;
	nb = 0;
	m = 1;
	j = 1;
	if (n[i] == '-')
	{
		m = -m;
		i++;
	}
	while (n[i])
	{
		if (j > 1 && n[i - 1] != '.')
			j *= 10;
		if (n[i] == '.')
			j *= 10;
		else
			nb = nb * 10 + (n[i] - 48);
		i++;
	}
	return (m * nb / j);
}

static void	errormsg(int ac)
{
	if (ac > 1)
		ft_printf("-----Invalid parameter----\n");
	ft_printf("List of psibles parameters:\n");
	ft_printf("'mandelbrot'\n'julia'\n'burning ship'\n'mandelbar'\n'perpendicular_mandelbrot'\n");
}

void	ft_check(int ac, char **av)
{
	if (ac == 2)
		if (!ft_strncmp(av[1], "mandelbrot", 12)
			|| !ft_strncmp(av[1], "burning ship", 13)
			|| !ft_strncmp(av[1], "mandelbar", 10)
			|| !ft_strncmp(av[1], "perpendicular mandelbrot", 26))
			return ;
	if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
		return ;
	errormsg(ac);
	exit(0);
}
