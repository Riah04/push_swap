/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:31:31 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/11 16:01:25 by andriraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *s)
{
	t_list	*tmp;
	int		min;

	tmp = s->top;
	min = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

static int	get_min_pos(t_stack *s)
{
	t_list	*tmp;
	int		position;
	int		i;

	assign_ranks(s);
	tmp = s->top;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			position = i;
		i++;
		tmp = tmp->next;
	}
	return (position);
}

void	simple_sort_1(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;
	int	i;

	assign_ranks(a);
	while (count_disorder(a) > 0.0)
	{
		pos = get_min_pos(a);
		if (pos < a->size / 2)
		{
			i = 0;
			while (i++ < pos)
				ra(a, bench);
		}
		else
		{
			i = 0;
			while (i++ < (a->size - pos))
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (b->size > 0)
		pa(a, b, bench);
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	while (count_disorder(a) > 0.0)
	{
		if (a->size <= 5)
			ft_small(a, b, bench);
		else
			simple_sort_1(a, b, bench);
	}
	bench->strategy = "Simple / O(n²)";
}
