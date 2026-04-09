/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:56:16 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/09 13:56:37 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ft_two(t_stack *a, t_bench *bench)
{
	t_list	*tmp;

	if (!a)
		return ;
	assign_ranks(a);
	tmp = a->top;
	if (tmp->index > tmp->next->index)
		sa(a, bench);
}

void	ft_three(t_stack *a, t_bench *bench)
{
	t_list	*tmp;

	assign_ranks(a);
	tmp = a->top;
	if (tmp->index == a->size - 1)
		ra(a, bench);
	if (a->top->index == 0)
	{
		sa(a, bench);
		ra(a, bench);
	}
}

void	ft_five(t_stack *a, t_stack *b, t_bench *bench)
{
	t_list	*tmp;
	int		k;

	assign_ranks(a);
	tmp = a->top;
	k = a->size - 1;
	while (tmp->index != k)
	{
		k = ft_take_max(a);
		if (tmp->index == k)
			pb(a, b, bench);
		if (a->size == 3)
			ft_three(a, bench);
		ra(a, bench);
		tmp = tmp->next;
	}
}
