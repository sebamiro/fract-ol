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

static void	print_justified(char *s, char *color)
{
	int len = ft_strlen(s) / 2;
	printf("%s<[%*s%*s]>\n\033[0;37m", color, 20 + len, s, 20 - len, "");
}

static void	errormsg(int ac)
{
	if (ac > 1)
		print_justified("||--------Invalid parameter--------||", "\033[0;31m");
	printf("\033[0;35m ==========================================\n");
	printf("%14sList of Fractals\n", "");
	printf(" ==========================================\n\033[0;37m");
	print_justified("'Mandelbrot'", "\033[0;36m");
	print_justified("'Julia'", "\033[0;36m");
	print_justified("'Burning Ship'", "\033[0;36m");
	print_justified("'Mandelbar'", "\033[0;36m");
	print_justified("'Heart'", "\033[0;36m");
	print_justified("'Buffalo'", "\033[0;36m");
	print_justified("'Perpendicular Mandelbrot'", "\033[0;36m");
	print_justified("'Celtic Mandelbrot'", "\033[0;36m");
	print_justified("'Celtic Mandelbar'", "\033[0;36m");
	print_justified("'Perpendicular Celtic'", "\033[0;36m");
}

char* str_tolower(char *str)
{
	int	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return str;
}

void	ft_check(int ac, char **av)
{
	char *param;
	if (ac == 2) {
		param = str_tolower(av[1]);
		if (!ft_strncmp(param, "mandelbrot", 12)
			|| !ft_strncmp(param, "burning ship", 13)
			|| !ft_strncmp(param, "mandelbar", 10)
			|| !ft_strncmp(param, "perpendicular mandelbrot", 26)
			|| !ft_strncmp(param, "celtic mandelbrot", 20)
			|| !ft_strncmp(param, "celtic mandelbar", 20)
			|| !ft_strncmp(param, "perpendicular celtic", 21)
			|| !ft_strncmp(param, "heart", 6)
			|| !ft_strncmp(param, "buffalo", 8)
			|| !ft_strncmp(param, "julia", 6)
			|| !ft_strncmp(param, "sierpinsky", 11))
			return ;
	}
	if (ac == 2 && !ft_strncmp(av[1], "-h", 3))
		errormsg(0);
	else
		errormsg(ac);
	exit(0);
}
