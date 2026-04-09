/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 08:40:36 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/08 16:06:14 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char c, va_list arg, int fd)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(arg, int), fd));
	if (c == 's')
		return (ft_printfs(va_arg(arg, char *), fd));
	if (c == 'p')
		return (ft_conv((unsigned long)va_arg(arg, void *), "0123456789abcdef", fd));
	if (c == 'd')
		return (ft_putnbr(va_arg(arg, int), fd));
	if (c == 'i')
		return (ft_putnbr(va_arg(arg, int), fd));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(arg, unsigned int), fd));
	if (c == 'x')
		return (ft_convert_base(va_arg(arg, unsigned int), "0123456789abcdef", fd));
	if (c == 'X')
		return (ft_convert_base(va_arg(arg, unsigned int), "0123456789ABCDEF", fd));
	if (c == '%')
		return (ft_putchar('%', fd));
	write(fd, "%", 1);
	ft_putchar(c, fd);
	return (0);
}
