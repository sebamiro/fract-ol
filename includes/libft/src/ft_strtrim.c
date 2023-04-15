/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:06:34 by seba              #+#    #+#             */
/*   Updated: 2022/08/25 11:04:57 by seba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	ft_find(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	e;

	e = 1;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (e && s1[i])
	{
		if (!ft_find(set, s1[i]))
			e = 0;
		i++;
	}
	if (i > j)
		return (ft_substr(s1, i, (j - i + 1)));
	e = 1;
	while (e && s1[j])
	{
		if (!ft_find(set, s1[j]))
			e = 0;
		j--;
	}
	i--;
	j++;
	return (ft_substr(s1, i, (j - i + 1)));
}
