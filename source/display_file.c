/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:49:35 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 10:19:26 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_wireframe(mlx_image_t *img, t_node a, t_node b, t_node *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = line_condition(fabs(step_x) > fabs(step_y),
			fabs(step_x), fabs(step_y));
	step_x /= max;
	step_y /= max;
	color = line_condition(a.set_color, a.color, set_color(a, b));
	color = (color * 16 + 15) * 16 + 15;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if ((a.x >= 0 && a.x <= param->win_x)
			&& (a.y >= 0 && a.y <= param->win_y))
			mlx_put_pixel(img, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_line(void *param)
{
	int		y;
	int		x;
	t_node	**matrix;

	matrix = param;
	y = -1;
	while (matrix[++y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y +1])
				plot_wireframe(matrix[0][0].img,
					matrix[y][x], matrix[y +1][x], &matrix[0][0]);
			if (!matrix[y][x].is_last)
				plot_wireframe(matrix[0][0].img,
					matrix[y][x], matrix[y][x +1], &matrix[0][0]);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
	}
}
