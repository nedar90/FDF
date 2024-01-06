/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:03:48 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/05 12:45:30 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoh(const char *nptr)
{
	int	number;
	int	digit;

	number = 0;
	while (*nptr != 'x')
		nptr++;
	nptr++;
	while (*nptr)
	{
		if (*nptr >= 'A' && *nptr <= 'F')
			digit = *nptr - 'A' + 10;
		else
			digit = *nptr - '0';
		number = number * 16 + digit;
		nptr++;
	}
	return (number);
}
