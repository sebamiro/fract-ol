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
	ft_printf("['mandelbrot']\n");
	ft_printf("['julia'] and two number between 3 and -3 and max 3 decimals\n");
	ft_printf("['burning ship']\n");
	ft_printf("['mandelbar']\n");
	ft_printf("['heart']\n");
	ft_printf("['buffalo']\n");
	ft_printf("['perpendicular mandelbrot']\n");
	ft_printf("['celtic mandelbrot']\n");
	ft_printf("['celtic mandelbar']\n");
	ft_printf("['perpendicular celtic']\n");
}

void	ft_check(int ac, char **av)
{
	if (ac == 2)
		if (!ft_strncmp(av[1], "mandelbrot", 12)
			|| !ft_strncmp(av[1], "burning ship", 13)
			|| !ft_strncmp(av[1], "mandelbar", 10)
			|| !ft_strncmp(av[1], "perpendicular mandelbrot", 26)
			|| !ft_strncmp(av[1], "celtic mandelbrot", 20)
			|| !ft_strncmp(av[1], "celtic mandelbar", 20)
			|| !ft_strncmp(av[1], "perpendicular celtic", 21)
			|| !ft_strncmp(av[1], "heart", 6)
			|| !ft_strncmp(av[1], "buffalo", 8)
			|| !ft_strncmp(av[1], "julia", 6))
			return ;
	if (ac == 4 && !ft_strncmp(av[1], "julia", 6)
		&& ft_strlen(av[2]) < 6 && ft_strlen(av[3]) < 6)
		return ;
	errormsg(ac);
	exit(0);
}
