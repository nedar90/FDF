/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:48:04 by nrajabia          #+#    #+#             */
/*   Updated: 2023/04/25 14:48:06 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <MLX42.h>
# include <ft_printf.h>

typedef struct s_node
{
	float		x;
	float		y;
	float		z;
	int			height;
	int			width;
	int			is_last;

	int			color;
	int			set_color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx;
	void		*img;
}		t_node;

/************************* LIBFT ***********************/
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_word_counter(char const *str, char c);
int		line_condition(int flag, int true_con, int false_con);
int		ft_atoh(const char *nptr);
int		ft_atoi(const char *nptr, int *is_color);
void	ft_error(int errnum);

/************************* LIBFDF ***********************/
void	set_param(t_node *a, t_node *b, t_node *param);
void	draw_line(void *param);
void	isometric(t_node *dot, double angle);
void	deal_key(void *param);
void	print_menu(t_node param);
void	by_default(t_node *param);
int		get_width(char *file_name);
int		get_height(char *file_name);
int		set_color(t_node a, t_node b);
t_node	**read_file(char	*file_name);

#endif
