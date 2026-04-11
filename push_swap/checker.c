/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:34:35 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/11 17:30:25 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "push_swap.h"

void	ft_ops(t_bench *bench, t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "rra\n") == 0)
		rra(a, bench);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a, bench);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, bench);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, bench);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b,  bench);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, bench);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, bench);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(a, bench);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, bench);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, bench);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, bench);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_bench	bench;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free_stack(b);
		return (1);
	}
	while ((line = get_next_line(0)) != NULL)
	{
		ft_ops(&bench, a, b, line);
		free(line);
	}
	if (count_disorder(a) > 0.0)
		return (ft_printf(2, "KO"), 0);
	free_stack(a);
	free_stack(b);
	return (ft_printf(2, "OK"), 0);
}
