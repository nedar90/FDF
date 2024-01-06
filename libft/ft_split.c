/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:06:47 by nrajabia          #+#    #+#             */
/*   Updated: 2022/12/17 10:07:03 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_free(char **array, int j)
{
	while (j >= 0)
	{
		free(array[j]);
		j--;
	}
	free(array);
	return (NULL);
}

// flag = 0 partition's counter
int	ft_splitlen(char const *s, char c, int flag)
{
	int	count;
	int	part;

	part = 1;
	count = 1;
	while (*s != '\0')
	{
		if (*s != c)
		{
			part++;
			while (*s != c && *s != '\0')
			{
				count++;
				s++;
			}
			if (flag)
				return (count);
		}
		else
			s++;
	}
	return (part);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		len[2];
	int		i;
	int		j;

	j = -1;
	len[0] = ft_splitlen(s, c, 0);
	array = malloc (len[0] * sizeof(char *));
	if (!array)
		return (NULL);
	while (++j < len[0] -1)
	{
		while (*s == c)
			s++;
		i = -1;
		len[1] = ft_splitlen(s, c, 1);
		array[j] = malloc(len[1] * sizeof(char));
		if (!array[j])
			return (ft_free(array, j));
		while (++i < len[1])
			array[j][i] = *s++;
		array[j][i -1] = '\0';
	}
	array[j] = 0;
	return (array);
}
