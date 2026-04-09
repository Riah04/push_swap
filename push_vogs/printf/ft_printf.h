/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 08:55:37 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/08 16:05:56 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_convert_base(unsigned int i, const char *str, int fd);
int	ft_convert(unsigned long i, const char *str, int fd);
int	ft_conv(unsigned long l, const char *str, int fd);
int	ft_putchar(char c, int fd);
int	ft_printfs(char *format, int fd);
int	ft_nb_count(int i);
int	ft_dig_count(unsigned int n);
int	ft_check_format(char c, va_list arg, int fd);
int	ft_putnbr(int i, int fd);
int	ft_putnbr_u(unsigned int i, int fd);
int	ft_2d(double d, int fd);

#endif
