/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key->c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:26:48 by nrajabia          #+#    #+#             */
/*   Updated: 2023/04/28 13:26:54 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key_hook2(t_node *param)
{
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->mlx);
	if (mlx_is_key_down(param->mlx, MLX_KEY_D))
		by_default(param);
}

void	deal_key_hook(t_node *param)
{
	if (mlx_is_key_down(param->mlx, MLX_KEY_RIGHT))
		param->shift_x += 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_LEFT))
		param->shift_x -= 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_DOWN))
		param->shift_y += 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_UP))
		param->shift_y -= 5;
	if (mlx_is_key_down(param->mlx, MLX_KEY_EQUAL))
		param->scale += 2;
	if (mlx_is_key_down(param->mlx, MLX_KEY_MINUS))
		param->scale -= 2;
	if (mlx_is_key_down(param->mlx, MLX_KEY_2))
		param->is_isometric = 0;
	if (mlx_is_key_down(param->mlx, MLX_KEY_3))
		param->is_isometric = 1;
	if (mlx_is_key_down(param->mlx, MLX_KEY_8))
		param->z_scale += 1;
	if (mlx_is_key_down(param->mlx, MLX_KEY_0))
		param->z_scale -= 1;
	if (mlx_is_key_down(param->mlx, MLX_KEY_4))
		param->angle += 0.05;
	if (mlx_is_key_down(param->mlx, MLX_KEY_6))
		param->angle -= 0.05;
}

void	deal_key(void *param)
{
	t_node	**matrix;

	matrix = param;
	deal_key_hook2(&matrix[0][0]);
	deal_key_hook(&matrix[0][0]);
	mlx_delete_image(matrix[0][0].mlx, matrix[0][0].img);
	matrix[0][0].img = mlx_new_image(matrix[0][0].mlx,
			matrix[0][0].win_x, matrix[0][0].win_y);
	mlx_image_to_window(matrix[0][0].mlx, matrix[0][0].img, 0, 0);
	draw_line(matrix);
}
