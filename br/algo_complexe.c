/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:51:24 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/03 01:09:31 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int		val_original;

	if (!s || !s->top)
		return ;
	tmp = s->top;
	while (tmp)
	{
		ranks = 0;
		val_original = tmp->value;
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
/*
static int	ft_take_max(t_stack *a)
{
	t_list	*tmp;
	int		max;

	if (!a || !a->top)
		return (0);
	tmp = a->top;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}*/

static void	ft_push_all_to_a(t_stack *a, t_stack *b)
{
	int	size;
	int	i;

	if (!b || !b->size)
		return ;
	size = b->size;
	if (size <= 0)
		return ;
	i = 0;
	while (i < size)
	{
		pa(a, b);
		i++;
	}
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int		count;
	int		nb;
	int		i;
	int		t;

	assign_ranks(a);
	count = ft_verif_bit(a->size - 1);
	t = 0;
	printf("size == %d", count);
	i = 0;
	while (i < count)
	{
		printf("size1 == %d", count);
		nb = a->size;
		while (nb > 0)
		{
			if (!((a->top->index >> i) & 1))
				pb(a, b);
			else
				ra(a);
			nb--;
		}
		ft_push_all_to_a(a, b);
		i++;
	}
}
