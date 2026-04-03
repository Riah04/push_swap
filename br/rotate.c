/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:40 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/02 22:26:34 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_list	*first;

	first = s->top;
	s->top = first->next;
	s->top->prev = NULL;
	first->prev = s->bottom;
	first->next = NULL;
	s->bottom->next = first;
	s->bottom = first;
}

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
