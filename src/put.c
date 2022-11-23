/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:40:26 by smiro             #+#    #+#             */
/*   Updated: 2022/11/23 12:41:26 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	put(t_fractol *fractol)
{
	double	x;
	double	y;

	fractol->value.pixel = init_complex(
			(fractol->value.max.x - fractol->value.min.x) / (W - 1),
			(fractol->value.max.y - fractol->value.min.y) / (H - 1));
	y = 0;
	
	while (y < H)
		{
			fractol->value.c.y = fractol->value.min.y + y * fractol->value.pixel.y;
			x = 0;
			while (x < W)
			{
				fractol->value.c.x = (fractol->value.min.x
						+ x * fractol->value.pixel.x);
				ft_putnbr_fd((int)(fractol->function(fractol)), fractol->fd);
				ft_putstr_fd(",0x", fractol->fd);
				ft_puthexnbr_fd(get_r(get_color(fractol->function(fractol), fractol)), 'X', fractol->fd);
				ft_puthexnbr_fd(get_g(get_color(fractol->function(fractol), fractol)), 'X', fractol->fd);
				ft_puthexnbr_fd(get_b(get_color(fractol->function(fractol), fractol)), 'X', fractol->fd);
				if (x < W - 1)
					ft_putchar_fd(' ', fractol->fd);
				else
					ft_putchar_fd('\n', fractol->fd);
				x++;
			}
			y++;
		}
	return (0);
}
