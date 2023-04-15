/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seba <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:04:20 by seba              #+#    #+#             */
/*   Updated: 2022/08/19 12:28:07 by seba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	totalpalabras(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) == 0)
		return (1);
	while (s[i])
	{
		if (s[i] == c)
		{
			j++;
			while (s[i] == c)
				i++;
			i--;
		}
		i++;
	}
	return (j + 2);
}

static size_t	totalletras(char const *s, size_t *j, char c)
{
	size_t	i;
	size_t	m;

	m = *j;
	while (s[*j] != c && s[*j])
		*j = *j + 1;
	i = *j - m;
	while (s[*j] == c)
		*j = *j + 1;
	return (i);
}

static void	protect(int i, char **str)
{
	int	j;

	if (i != 0)
	{
		j = 0;
		while (j <= i)
		{
			free(str[j]);
			j++;
		}
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	t;

	j = 0;
	i = 0;
	s2 = ft_strtrim(s, &c);
	str = ft_calloc(totalpalabras(s2, c), sizeof(char *));
	if (!str)
		return (NULL);
	while (i < totalpalabras(s2, c) - 1)
	{
		t = j;
		str[i] = ft_substr(s2, t, totalletras(s2, &j, c));
		if (!str[i])
		{
			protect((int)i, str);
			return (NULL);
		}
		i++;
	}
	return (str);
}
