/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:38:33 by nrajabia          #+#    #+#             */
/*   Updated: 2023/04/27 14:38:40 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_node param)
{
	char	*menu;

	menu = "D: return to default";
	mlx_put_string(param.mlx, menu, 10, 5);
	menu = "up, down, left, right: move picture";
	mlx_put_string(param.mlx, menu, 10, 25);
	menu = "3, 2: 3d/2d mode; +, -: zoom";
	mlx_put_string(param.mlx, menu, 10, 45);
	menu = "8, 0: z-scale; 4, 6: rotation";
	mlx_put_string(param.mlx, menu, 10, 65);
}
