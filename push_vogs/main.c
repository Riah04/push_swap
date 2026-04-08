/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 06:21:15 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/08 16:02:42 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_flags	get_flags(int argc, char **argv)
{
	t_flags	f;

	f.bench = has_flag(argv, argc, "--bench");
	f.adaptive = has_flag(argv, argc, "--adaptive");
	f.simple = has_flag(argv, argc, "--simple");
	f.medium = has_flag(argv, argc, "--medium");
	f.complexe = has_flag(argv, argc, "--complex");
	return (f);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_bench	*bench;
	char	*str;
	int		fd;

	flags = get_flags(argc, argv);
	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_printf(1, "%f\n", 0.4502);
	fd = 2;
	bench = malloc(sizeof(t_bench));
	str = "lol";
	ft_init_bench(bench);
	if (flags.simple)
		simple_sort(a, b, bench);
	if (flags.medium)
		medium_sort(a, b, bench);
	if (flags.complexe)
		ft_radix(a, b, bench);
	if (flags.adaptive)
		ft_adaptive(a, b, argv, argc, bench);
	if (flags.bench)
		ft_bench(argv, argc, bench, fd);
	else
		ft_adaptive(a, b, argv, argc, bench);
	return (0);
}
