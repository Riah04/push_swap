/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:51:24 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/10 13:55:03 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_verif_bit(int k)
{
	int	count;

	count = 0;
	while (k)
	{
		count++;
		k = k >> 1;
	}
	return (count);
}

static void	ft_push_all_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	int	size;
	int	i;

	if (!b || !b->size)
		return ;
	size = b->size;
	i = 0;
	while (i < size)
	{
		pa(a, b, bench);
		i++;
	}
	return ;
}

static void	ft_radix_1(t_stack *a, t_stack *b, t_bench *bench)
{
	int	count;
	int	nb;
	int	i;

	assign_ranks(a);
	count = ft_verif_bit(a->size - 1);
	i = 0;
	if (a->size > 5)
	{
		while (i <= count)
		{
			nb = a->size;
			while (nb > 0)
			{
				if (!((a->top->index >> i) & 1))
					pb(a, b, bench);
				else
					ra(a, bench);
				nb--;
			}
			ft_push_all_to_a(a, b, bench);
			i++;
		}
	}
}

void	ft_radix(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 5)
		ft_small(a, b, bench);
	else
		ft_radix_1(a, b, bench);
	bench->strategy = "Complex / O(n log n)";
}
