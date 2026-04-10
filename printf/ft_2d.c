/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:44:00 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/09 20:03:44 by andriraz         ###   ########.fr       */
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
	k = d * 100;
	if (k >= 0)
		count += ft_putnbr_u(k, fd);
	count += ft_putchar('.', fd);
	j = ((d * 100) - (k)) * 100;
	if (j < 10)
	{
		count += ft_putnbr_u(0, fd);
		count += ft_putnbr_u(j, fd);
	}
	else
		count += ft_putnbr_u(j, fd);
	return (count);
}
