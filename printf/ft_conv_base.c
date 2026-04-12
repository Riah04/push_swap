/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 08:36:19 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/15 08:52:22 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned long i, const char *str, int fd)
{
	long				k;
	int					len_1;
	int					len_t;

	k = 0;
	len_1 = 0;
	len_t = 0;
	while (str[len_1])
		len_1++;
	if (i >= (unsigned long)len_1)
		len_t += ft_convert((i / len_1), str, fd);
	len_t += ft_putchar(str[i % len_1], fd);
	return (len_t);
}

int	ft_conv(unsigned long l, const char *str, int fd)
{
	int	len_t;

	len_t = 0;
	if (l == 0)
		return (ft_printfs("(nil)", fd));
	if (l)
	{
		len_t += ft_printfs("0x", fd);
		len_t += ft_convert(l, str, fd);
	}
	return (len_t);
}

int	ft_convert_base(unsigned int i, const char *str, int fd)
{
	int	len;
	int	len_t;

	len_t = 0;
	len = 0;
	while (str[len])
		len++;
	if (i >= (unsigned int)len)
		len_t += ft_convert_base(i / len, str, fd);
	ft_putchar(str[i % len], fd);
	return (len_t + 1);
}
