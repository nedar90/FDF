/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:29:35 by nrajabia          #+#    #+#             */
/*   Updated: 2023/03/13 09:41:18 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	shift_line(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = FALSE;
	while (str[i])
	{
		if (flag)
			str[j++] = str[i];
		if (str[i] == '\n')
			flag = TRUE;
		str[i++] = '\0';
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE +1];
	char		*line;
	int			num;

	if (BUFFER_SIZE < 1 || fd == -1 || FOPEN_MAX < fd)
		ft_error(ENOENT);
	line = ft_strjoin(0, buff);
	if (shift_line(buff))
		return (line);
	num = read(fd, buff, BUFFER_SIZE);
	if (num < 0)
	{
		free(line);
		ft_error(errno);
	}
	while (num > 0)
	{
		line = ft_strjoin(line, buff);
		if (shift_line(buff))
			break ;
		num = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}
