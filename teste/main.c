/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 05:20:01 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/09 16:31:57 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *s)
{
	t_list	*tmp;
	t_list	*current;

	if (!s || s->top == NULL)
		return ;
	current = s->top;
	while (current->next)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(s);
}
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;

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
	push_swap(argc, argv, a, b, &bench);
	free_stack(a);
	free_stack(b);
	return (0);
}
