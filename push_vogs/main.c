/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 06:21:15 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/07 16:59:53 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

// // CETTE FONCTION N'EST LA QUE POUR LE TEST
// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	t_list	*tmp;

// 	write(1, "A: ", 3);
// 	tmp = a->top;
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	write(1, "\n", 1);
// 	write(1, "B: ", 3);
// 	tmp = b->top;
// 	while (tmp)
// 	{
// 		printf("%d", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	write(1, "\n\n", 2);
// }
t_flags	get_flags(int argc, char **argv)
{
	t_flags	f;

	f.bench = has_flag(argv, argc, "--bench");
	f.adaptive = has_flag(argv, argc, "--adaptive");
	f.simple = has_flag(argv, argc, "--simple");
	f.medium = has_flag(argv, argc, "--medium");
	f.complexe = has_flag(argv, argc, "--complexe");
	return (f);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_bench *bench = NULL;

	flags = get_flags(argc, argv);
	if (argc < 2)
		return (1);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	// if (flags.bench)
	// 	ft_bench(argv, argc);
	ft_init_bench(bench);
	if (flags.simple)
		simple_sort(a, b, bench);
	if (flags.medium)
		medium_sort(a, b, bench);
	if (flags.complexe)
		ft_radix(a, b, bench);
	if (flags.adaptive)
		return (0);
}
