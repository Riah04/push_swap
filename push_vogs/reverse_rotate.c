/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:29 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/06 14:45:09 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *s)
{
	t_list	*last;

	last = s->bottom;
	s->bottom = last->prev;
	s->bottom->next = NULL;
	last->next = s->top;
	last->prev = NULL;
	s->top->prev = last;
	s->top = last;
}

void	rra(t_stack *a, t_bench *bench)
{
	if (a->size < 2)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
	bench->rra++;
}

void	rrb(t_stack *b, t_bench *bench)
{
	if (b->size < 2)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	bench->rrb++;
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	bench->rrr++;
}
