/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:18 by andriraz          #+#    #+#             */
/*   Updated: 2026/03/28 14:54:02 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	*node;

	if (b->size == 0)
		return ;
	node = b->top;
	b->top = node->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	b->size--;
	node->next = a->top;
	node->prev = NULL;
	if (a->top)
		a->top->prev = node;
	else
		a->bottom = node;
	a->top = node;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*node;

	if (a->size == 0)
		return ;
	node = a->top;
	a->top = node->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	a->size--;
	node->next = b->top;
	node->prev = NULL;
	if (b->top)
		b->top->prev = node;
	else
		b->bottom = node;
	b->top = node;
	b->size++;
	write(1, "pb\n", 3);
}
