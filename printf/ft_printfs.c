/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:14:30 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/08 13:47:01 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_printfs(char *format, int fd)
{
	int		i;

	i = 0;
	if (format == NULL)
	{
		format = "(null)";
		while (format[i])
		{
			ft_putchar(format[i], fd);
			i++;
		}
		return (i);
	}
	while (format[i])
	{
		ft_putchar(format[i], fd);
		i++;
	}
	return (i);
}
