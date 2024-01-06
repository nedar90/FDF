/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:31:12 by nrajabia          #+#    #+#             */
/*   Updated: 2023/02/21 15:27:03 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putuns(unsigned int num);
int		ft_putstr(char *s);
int		ft_hexnbr(unsigned int n, char format);
int		ft_hexadd(unsigned long num);
void	ft_printnum(unsigned long n, char format, unsigned int base);
size_t	ft_nbrlen(unsigned long num, unsigned int base);
size_t	ft_strlen(const char *s);

#endif
