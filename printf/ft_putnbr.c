/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:03:22 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/15 07:58:45 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i, int fd)
{
	int	j;
	int	k;
	int	len;

	len = ft_nb_count(i);
	if (i == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (i >= 10)
	{
		j = i / 10;
		k = i % 10;
		ft_putnbr(j, fd);
		ft_putnbr(k, fd);
	}
	else if (i < 0)
	{
		write(fd, "-", 1);
		i *= -1;
		ft_putnbr(i, fd);
	}
	else
		ft_putchar(i + '0', fd);
	return (len);
}

int	ft_putnbr_u(unsigned int i, int fd)
{
	int	j;
	int	k;
	int	len;

	len = ft_dig_count(i);
	if (i >= 10)
	{
		j = i / 10;
		k = i % 10;
		ft_putnbr_u(j, fd);
		ft_putnbr_u(k, fd);
	}
	else
		ft_putchar(i + '0', fd);
	return (len);
}
