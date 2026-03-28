
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
		tmp->value = ranks;
		tmp = tmp->next;
	}
}

static int	get_chunk_size(t_stack *a)
{
	int	chunk_size;

	chunk_size = ft_sqrt(a->size);
	return (chunk_size);
}

void	push_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_max)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size && a->size > 0)
	{
		if (a->top->value >= chunk_min && a->top->value < chunk_max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	back_to_a(t_stack *s1, t_stack *s2)
{
	t_list	*tmp;
	int		max;

	while (s2->size > 0)
	{
		tmp = s2->top;
		max = tmp->value;
		while (tmp)
		{
			if (tmp->value > max)
				max = tmp->value;
			tmp = tmp->next;
		}
		if (s2->top->value == max)
			pa(s1, s2);
		else
			rb(s2);
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		size;

	assign_ranks(a);
	size = get_chunk_size(a);
	min = 0;
	while (a->size > 0)
	{
		push_chunk(a, b, min, min + size);
		min += size;
	}
	back_to_a(a, b);
}
