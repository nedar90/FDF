/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:56:19 by nrajabia          #+#    #+#             */
/*   Updated: 2023/04/01 15:42:54 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(char *line, t_node **matrix, int y)
{
	char	**nodes;
	int		x;

	nodes = ft_split(line, ' ');
	x = 0;
	while (nodes[x])
	{
		matrix[y][x].z = ft_atoi(nodes[x], &matrix[y][x].set_color);
		if (matrix[y][x].set_color)
			matrix[y][x].color = ft_atoh(nodes[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free (nodes[x++]);
	}
	free (nodes);
	free (line);
	matrix[y][--x].is_last = 1;
}

t_node	**ft_memalloc(char *file_name)
{
	t_node	**matrix;
	int		height;
	int		width;
	int		i;

	width = get_width(file_name);
	if (!width || width < 2)
		ft_error(EIO);
	height = get_height(file_name);
	matrix = (t_node **)malloc((height + 1) * sizeof(t_node *));
	i = -1;
	while (++i <= height)
		matrix[i] = (t_node *)malloc((width + 1) * sizeof(t_node));
	matrix[0][0].width = width;
	matrix[0][0].height = height;
	return (matrix);
}

t_node	**read_file(char *file_name)
{
	t_node	**matrix;
	int		fd;
	char	*line;
	int		y;

	matrix = ft_memalloc(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix(line, matrix, y++);
	}
	matrix[y] = NULL;
	close (fd);
	return (matrix);
}
