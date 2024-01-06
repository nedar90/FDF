/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:55:01 by nrajabia          #+#    #+#             */
/*   Updated: 2023/04/25 14:55:04 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	find_scale(t_node *param)
{
	int	x_scale;
	int	y_scale;

	x_scale = param->win_x / param->height;
	y_scale = param->win_y / param->width;
	return (line_condition(x_scale > y_scale, y_scale, x_scale));
}

void	by_default(t_node *param)
{
	param->scale = find_scale(param);
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->shift_x = param->win_x / 2;
	param->shift_y = param->win_y / 3;
}

void	set_zoom(t_node *a, t_node *b, t_node *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
}

void	set_param(t_node *a, t_node *b, t_node *param)
{
	set_zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}

int	set_color(t_node a, t_node b)
{
	int	color;

	color = line_condition((b.z || a.z), 0xfc0345, 0xBBFAFF);
	return (color);
}
