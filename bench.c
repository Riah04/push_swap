/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:54:36 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/29 14:39:49 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s, char *s1)
{
	int	i;

	i = 0;
	while (s[i] || s1[i])
	{
		if (s[i] != s1[i])
			return (s1[i] - s1[i]);
		i++;
	}
	return (0);
}

void	ft_bench(char *argv, int argc)
{
	int	i;
	int	d;

	i = 0;
	if (ft_strcmp("--bench", argv) == 0)
	{
		ft_printf("[bench] disorder: %f\n", d);
		ft_printf("[bench] strategy: %f\n", d);
		ft_printf("[bench] total_ops: %f\n", d);
		ft_printf("[bench] sa:	%d	sb:	%d ss:	%d	pa:	%d	pb:	%d\n");
		ft_printf("[bench] ra:	%d	rb:	%d rr:	%d	rra:	%d");
		ft_printf("rrb:	%d	rrr:	%d");
	}
}
