/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student->42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:54:36 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/07 17:16:16 by nmariah          ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_strcmp(char *s, char *s1)
{
	int	i;

	i = 0;
	while (s[i] || s1[i])
	{
		if (s[i] != s1[i])
			return ((unsigned int)s[i] - (unsigned int)s1[i]);
		i++;
	}
	return (0);
}

void	ft_init_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->disorder = 0;
	bench->strategy = NULL;
	bench->pa = 0;
	bench->pb = 0;
	bench->pa = 0;
	bench->ra = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
}
/// @brief /////////////////////////////////////////////////////////////////////////////

static int	count_word(const char *str, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static unsigned int	len_word(const char *str, int i, char c)
{
	unsigned int	start;

	start = i;
	while (str[i] && str[i] != c)
		i++;
	return (i - start);
}

static void	free_tab(char **tab, int k)
{
	int	j;

	j = 0;
	while (k > j)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static char	*word_allocation(const char *str, int *i, char c)
{
	int		len;
	char	*word;
	int		j;

	j = 0;
	while (str[*i] == c)
		(*i)++;
	len = len_word(str, *i, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (j < len)
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	words = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (k < words)
	{
		result[k] = word_allocation(s, &i, c);
		if (!result[k])
		{
			free_tab(result, k - 1);
			return (NULL);
		}
		k++;
	}
	result[k] = NULL;
	return (result);
}
int	has_flag(char **argv, int argc, char *flag)
{
	int		count;
	char	**split;
	int		k;
	int		j;

	k = 0;
	count = 0;
	while (argc > k)
	{
		j = 0;
		count = count_word(argv[k], ' ');
		split = ft_split(argv[k], ' ');
		while (j < count)
		{
			if (ft_strcmp(split[j], flag) == 0)
				return (free_tab(split, count), 1);
			j++;
		}
		free_tab(split, count);
		k++;
	}
	return (0);
}

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

void	pa(t_stack *a, t_stack *b, t_bench *bench)
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
	bench->pa++;
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
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
	bench->pb++;
}



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

void	ra(t_stack *a, t_bench *bench)
{
	if (a->size < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
	bench->ra++;
}

void	rb(t_stack *b, t_bench *bench)
{
	if (b->size < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
	bench->rb++;
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	bench->rr++;
}


void	ft_radix(t_stack *a, t_stack *b, t_bench *bench)
{
	int		count;
	int		max;
	int		nb;
	int		i;

	//ft_init_bench(bench);
	assign_ranks(a);
	max = ft_take_max(a);
	count = ft_verif_bit(max);
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

/// @brief ////////////////////////////////////////////////////////
void	ft_bench(char **argv, int argc, t_bench *bench)
{
	if (has_flag(argv, argc, "--bench") == 1)
	{
		printf("[bench] disorder: %f\n", bench->disorder);
		printf("[bench] strategy: %s\n", bench->strategy);
		printf("[bench] total_ops: %d\n", bench->total_ops);
		printf("[bench] sa:	%d	sb:	%d ss:	%d	pa:	%d	pb:	%d\n", bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
		printf("[bench] ra:	%d	rb:	%d rr:	%d	rra:	%d	", bench->ra, bench->rb, bench->rr, bench->rra);
		printf("rrb:	%d	rrr:	%d\n", bench->rrb, bench->rrr);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_bench bench;
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	ft_init_bench(&bench);
	if (has_flag(argv, argc, "--complex") == 1)
		ft_radix(a, b, &bench);
	ft_bench(argv, argc, &bench);
	return (0);
}