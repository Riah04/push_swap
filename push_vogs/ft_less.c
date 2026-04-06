/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:56:16 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/06 16:39:36 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_stack *s)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		ranks;
	int		og_value;

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

void	ft_three(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	t_bench	*bench;

	assign_ranks(a);
	tmp = a->top;
	if (tmp->index == a->size)
	{
		ra(a, bench);
	}
	if (a->top->index == 0)
	{
		sa(a, bench);
		ra(a, bench);
	}
}
