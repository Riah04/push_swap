/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 08:40:47 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/08 13:45:13 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	va_list	arg;
	int		i;
	int		j;

	if (!format)
		return (-1);
	i = 0;
	j = 0;
	va_start(arg, format);
	while (format[j] != '\0' )
	{
		if (format[j] == '%')
		{
			i += ft_check_format(format[j + 1], arg, fd);
			j++;
		}
		else
			i += write(fd, &format[j], 1);
		j++;
	}
	va_end(arg);
	return (i);
}
