/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:25:58 by seba              #+#    #+#             */
/*   Updated: 2022/10/31 23:16:29 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include "ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *s, ...);

int	ftputchar(char c);

int	ftputstr(const char *s, va_list ap);

int	ftputnbr(int n);

int	ftputuint(unsigned int n);

int	puthexnbr(unsigned int n, char x);

int	putptr(unsigned long long ptr);

int	handlechar(va_list ap);

int	handlenbr(va_list ap, char c);

int	handlestr(va_list ap);

int	handleptr(va_list ap);

#endif
