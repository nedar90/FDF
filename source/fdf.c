/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:23:12 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 10:22:36 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// check for free memory

void	set_default(t_node *param)
{
	param->win_x = 1920;
	param->win_y = 1080;
	by_default(param);
	param->mlx = mlx_init(param->win_x, param->win_y, "FDF", true);
	param->img = mlx_new_image(param->mlx, param->win_x, param->win_y);
}

int	main(int ac, char **av)
{
	t_node	**matrix;

	if (ac != 2)
		ft_error(EBADF);
	matrix = read_file(av[1]);
	set_default(&matrix[0][0]);
	print_menu(matrix[0][0]);
	mlx_image_to_window(matrix[0][0].mlx, matrix[0][0].img, 0, 0);
	mlx_loop_hook(matrix[0][0].mlx, draw_line, matrix);
	mlx_loop_hook(matrix[0][0].mlx, deal_key, matrix);
	mlx_loop(matrix[0][0].mlx);
	mlx_terminate(matrix[0][0].mlx);
}
