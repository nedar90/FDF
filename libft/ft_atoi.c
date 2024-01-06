/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:01:26 by nrajabia          #+#    #+#             */
/*   Updated: 2023/04/10 10:01:31 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *nptr, int *set_color)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (*nptr == ' '
		|| (*nptr >= 10 && *nptr <= 13)
		|| *nptr == '\t')
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + *nptr - 48;
		nptr++;
	}
	*set_color = line_condition(*nptr == ',', 1, 0);
	return (sign * number);
}
