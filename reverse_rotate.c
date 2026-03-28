/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:29 by andriraz          #+#    #+#             */
/*   Updated: 2026/03/25 11:37:30 by andriraz         ###   ########.fr       */
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

void	rra(t_stack *a)
{
	if (a->size < 2)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (b->size < 2)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}