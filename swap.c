/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:56 by andriraz          #+#    #+#             */
/*   Updated: 2026/03/25 11:37:58 by andriraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_list	*first;
	t_list	*second;

	first = s->top;
	second = s->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	s->top = second;
	if (s->size == 2)
		s->bottom = first;
}

void	sa(t_stack *a)
{
	if (a->size < 2)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (b->size < 2)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
