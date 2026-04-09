/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:12:10 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/09 16:14:47 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	free_tab(char **tab, int k)
{
	int	j;

	j = 0;
	if (!tab)
		return ;
	while (k > j)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static void		init_flag(t_flags *f)
{
	if (!f)
		return ;
	f->adaptive = 0;
	f->bench = 0;
	f->medium = 0;
	f->simple = 0;
	f->complex = 0;
}

static t_flags	*get_flags(char **split, t_flags *f)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strcmp(split[i], "--adaptive") == 0)
			f->adaptive = 1;
		if (ft_strcmp(split[i], "--simple") == 0)
			f->simple = 1;
		if (ft_strcmp(split[i], "--medium") == 0)
			f->medium = 1;
		if (ft_strcmp(split[i], "--complex") == 0)
			f->complex = 1;
		if (ft_strcmp(split[i], "--bench") == 0)
			f->bench = 1;
		i++;
	}
	return (f);
}

t_flags	has_flags(char **argv, int argc, t_flags *f)
{
	int		count;
	char	**split;
	int		k;
	int		j;
	int		i;

	k = 1;
	count = 0;
	init_flag(f);
	while (argc > k)
	{
		j = 0;
		count = count_word(argv[k], ' ');
		split = ft_split(argv[k], ' ');
		i = 0;
		f = get_flags(split, f);
		free_tab(split, count);
		k++;
	}
	return (*f);
}

void	push_swap(int argc, char **argv, t_stack *a, t_stack *b, t_bench *bench)
{
	t_flags	flags;

	flags = has_flags(argv, argc, &flags);
	ft_init_bench(bench);
	bench->disorder = count_disorder(a);
	if (flags.simple)
		simple_sort(a, b, bench);
	else if (flags.medium)
		medium_sort(a, b, bench);
	else if (flags.complex)
		ft_radix(a, b, bench);
	else if (flags.adaptive)
		ft_adaptive(a, b, bench);
	else
		ft_adaptive(a, b, bench);
	if (flags.bench)
		ft_bench(bench, 2);
}
