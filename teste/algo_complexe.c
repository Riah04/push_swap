/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:51:24 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/09 15:19:39 by nmariah          ###   ########.fr       */
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

static void	assign_ranks(t_stack *s)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		ranks;

	if (!s || !s->top)
		return ;
	tmp = s->top;
	while (tmp)
	{
		ranks = 0;
		tmp1 = s->top;
		while (tmp1)
		{
			if (tmp1->value < tmp->value)
				ranks++;
			tmp1 = tmp1->next;
		}
		tmp->index = ranks;
		tmp = tmp->next;
	}
}

static void	ft_push_all_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	int size, i;
	if (!b || !b->size)
		return ;
	size = b->size;
	if (size <= 0)
		return ;
	i = 0;
	while (i < size)
	{
		pa(a, b, bench);
		i++;
	}
}

void	ft_radix(t_stack *a, t_stack *b, t_bench *bench)
{
	int	count;
	int	nb;
	int	i;

	assign_ranks(a);
	count = ft_verif_bit(a->size - 1);
	i = 0;
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
	bench->strategy = "Complex / O(n log n)";
}
