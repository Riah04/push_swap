/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 08:11:29 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/12 15:34:38 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	reverse_rotate(t_stack *s)
{
	t_list	*last;

	if (s->size < 2)
		return ;
	last = s->bottom;
	s->bottom = last->prev;
	s->bottom->next = NULL;
	last->next = s->top;
	last->prev = NULL;
	s->top->prev = last;
	s->top = last;
}

void	rra_b(t_stack *a)
{
	if (a->size < 1)
		return ;
	reverse_rotate(a);
}

void	rrb_b(t_stack *b)
{
	if ((b->size < 1))
		return ;
	reverse_rotate(b);
}

void	rrr_b(t_stack *a, t_stack *b)
{
	if ((b->size < 1) && (a->size < 1))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}

static void	rotate(t_stack *s)
{
	t_list	*first;
	
	if (s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	s->top->prev = NULL;
	first->prev = s->bottom;
	first->next = NULL;
	s->bottom->next = first;
	s->bottom = first;
}

void	ra_b(t_stack *a)
{
	if (a->size < 2)
		return ;
	else
		rotate(a);
}

void	rb_b(t_stack *b)
{
	if ((b->size < 2))
		return ;
	else
		rotate(b);
}

void	rr_b(t_stack *a, t_stack *b)
{
	if ((b->size < 2) && (a->size < 2))
		return ;
	else
	{
		rotate(a);
		rotate(b);
	}
}

static void	swap(t_stack *s)
{
	t_list	*first;
	t_list	*second;

	if (s->size < 2)
		return ;
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

void	sa_b(t_stack *a)
{
	if (a->size < 2)
		return ;
	else
		swap(a);
}

void	sb_b(t_stack *b)
{
	if (b->size < 2)
		return ;
	else
		swap(b);
}

void	ss_b(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	else
	{
		swap(a);
		swap(b);
	}
}
void	pa_b(t_stack *a, t_stack *b)
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
}

void	pb_b(t_stack *a, t_stack *b)
{
	t_list	*node;

	if (a->size > 0)
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
}
