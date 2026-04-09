#include "push_swap.h"

static void	assign_ranks(t_stack *s)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		ranks;

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

static int	get_chunk_size(t_stack *a)
{
	int	chunk_size;

	chunk_size = ft_sqrt(a->size);
	return (chunk_size);
}

void	push_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_max, t_bench *bench)
{
	int	i;
	int	init;
	int	mid;

	i = 0;
	init = a->size;
	mid = (chunk_max + chunk_min) / 2;
	while (i < init)
	{
		if (a->top->index >= chunk_min && a->top->index < chunk_max)
		{
			pb(a, b, bench);
			if (b->top->index < mid)
				rb(b, bench);
		}
		else
		{
			ra(a, bench);
		}
		i++;
	}
}

void	back_to_a(t_stack *s1, t_stack *s2, t_bench *bench)
{
	int	max;
	int	pos;
	int	i;

	while (s2->size > 0)
	{
		max = get_max(s2);
		pos = get_max_pos(s2);
		if (s2->top->value == max)
			pa(s1, s2, bench);
		else if (pos < s2->size / 2)
		{
			i = 0;
			while (i++ < pos)
				rb(s2, bench);
			pa(s1, s2, bench);
		}
		else
		{
			i = 0;
			while (i++ < (s2->size - pos))
				rrb(s2, bench);
		}
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min;
	int	size;

	assign_ranks(a);
	size = get_chunk_size(a);
	min = 0;
	while (a->size > 0)
	{
		push_chunk(a, b, min, min + size, bench);
		min += size;
	}
	back_to_a(a, b, bench);
	bench->strategy = "Medium / O((n√n))";
}
