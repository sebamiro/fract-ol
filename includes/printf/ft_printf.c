/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:37:13 by seba              #+#    #+#             */
/*   Updated: 2022/10/29 13:19:34 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int		total;
	va_list	ap;

	va_start(ap, s);
	total = ft_putctype(s, ap);
	va_end(ap);
	return (total);
}
