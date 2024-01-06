/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:21:11 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/05 13:21:14 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_condition(int flag, int true_con, int false_con)
{
	if (flag)
	{
		return (true_con);
	}
	return (false_con);
}
