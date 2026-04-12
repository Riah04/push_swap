/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:34:35 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/12 15:36:52 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "../push_swap.h"

int	ft_ops( t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "rra\n") == 0)
		rra_b(a);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_b(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_b(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_b(a, b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_b(b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_b(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_b(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa_b(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_b(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_b(a, b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_b(a, b);
	else
		return (0);
	return (1);
}

void	ft_execute(t_stack *a, t_stack *b, char *line)
{
	if (!line || !a || !b)
		return ;
	else
	{
		if ((ft_ops(a, b, line)) == 0)
		{
			free(line);
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a && !b)
		return (1);
	if (!parse_args_bonus(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free_stack(b);
		return (1);
	}
	while ((line = get_next_line(0)) != NULL)
		ft_execute(a, b, line);
	if (count_disorder(a) > 0.0 || b->size > 0)
		return (ft_printf(1, "KO\n"), 0);
	if (count_disorder(a) == 0.0 && b->size == 0)
		ft_printf(1, "OK\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
