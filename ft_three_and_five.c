/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_and_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:42:38 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/10 14:15:30 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_two(t_stack *a, t_bench *bench)
{
	if (a->size == 1)
		return ;
	if (a->size == 2 && (a->top->value > a->top->next->value))
		sa(a, bench);
	return ;
}

static void	ft_three(t_stack *a, t_bench *bench)
{
	int		i;
	int		b;

	if (!a)
		return ;
	assign_ranks(a);
	b = a->top->next->index;
	i = a->top->next->next->index;
	if (a->top->index > b && b < i && a->top->index < i)
		sa(a, bench);
	else if (a->top->index > b && b > i)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (a->top->index > b && b < i && a->top->index > i)
		ra(a, bench);
	else if (a->top->index < b && b > i && a->top->index < i)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (a->top->index < b && b > i && a->top->index > i)
		rra(a, bench);
	return ;
}

static int	get_min_pos(t_stack *s, int min)
{
	t_list	*tmp;
	int		position;
	int		i;

	tmp = s->top;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index == min)
			position = i;
		i++;
		tmp = tmp->next;
	}
	return (position);
}

static void	ft_five(t_stack *a, t_stack *b, t_bench *bench)
{
	t_list	*tmp;
	int		i;

	if (!a)
		return ;
	i = 0;
	assign_ranks(a);
	tmp = a->top;
	while (i <= 1)
	{
		while (get_min_pos(a, i) != 0)
			ra(a, bench);
		i++;
		pb(a, b, bench);
	}
	if (a->size == 3)
		ft_three(a, bench);
	while (b->size != 0)
		pa(a, b, bench);
	return ;
}

void	ft_small(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a)
		return ;
	if (a->size <= 2)
		ft_two(a, bench);
	else if (a->size == 3)
		ft_three(a, bench);
	else
		ft_five(a, b, bench);
	return ;
}
