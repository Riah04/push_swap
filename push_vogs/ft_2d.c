/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:44:00 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/08 15:46:13 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_2d(double d, int fd)
{
	int	count;
	int	k;
	int	j;

	count = 0;
	if (d < 0)
		return (0);
	k = d;
	if (k >= 0)
		count += ft_putnbr_u(k, fd);
	count += ft_putchar('.', fd);
	j = ((d) - k);
	if (j < 10)
	{
		count += ft_putnbr(0, fd);
		count += ft_putnbr(j, fd);
	}
	else
		count += ft_putnbr(j, fd);
	return (count);
}

