/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 05:20:01 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/12 10:32:38 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	t_flags	flags;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free_stack(b);
		return (1);
	}
	flags = has_flags(argv, argc, &flags);
	push_swap(&flags, a, b, &bench);
	free_stack(a);
	free_stack(b);
	return (0);
}
