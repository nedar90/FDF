/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:51:19 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/01 11:51:21 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		height;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		strerror(errno);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free (line);
		height++;
	}
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		ft_error(ENOENT);
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = ft_word_counter(line, ' ');
	while (line)
	{
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (width);
}
