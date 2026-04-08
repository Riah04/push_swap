/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dig_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:17:58 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/01 13:38:06 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dig_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10 && n >= 0)
		return (1);
	while (n > 0 && n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_nb_count(int i)
{
	int	k;

	k = 0;
	if (i <= 0)
	{
		k += 1;
		i *= -1;
	}
	while (i != 0)
	{
		i = i / 10;
		k++;
	}
	return (k);
}
