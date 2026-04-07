/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 08:38:28 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/07 16:55:17 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	ft_verif_bit(int k)
{
	int	count;

	count = 0;
	while (k)
	{
		count++;
		k = k >> 1;
	}
	return (count);
}

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
		og_value = tmp->value;
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

static void	ft_push_all_to_a(t_stack *a, t_stack *b)
{
	int	size;
	int	i;
	t_bench *bench;

	bench = NULL;
	ft_init_bench(bench);
	if (!b || !b->size)
		return ;
	size = b->size;
	if (size <= 0)
		return ;
	i = 0;
	while (i < size)
	{
		pa(a, b, bench);
		i++;
	}
}

void	ft_radix(t_stack *a, t_stack *b, t_bench *bench)
{
	int		count;
	int		max;
	int		nb;
	int		i;
	t_list	*tmp;

	ft_init_bench(bench);
	assign_ranks(a);
	max = ft_take_max(a);
	count = ft_verif_bit(max);
	tmp = a->top;
	i = 0;
	while (i < count)
	{
		nb = a->size;
		while (nb > 0)
		{
			if ((a->top->index >> i) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			nb--;
		}
		ft_push_all_to_a(a, b);
		i++;
	}
}
