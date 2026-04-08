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

void	ft_init_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->disorder = 0.00;
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

void	ft_bench(char **argv, int argc, t_bench *bench, int fd)
{
	if (has_flag(argv, argc, "--bench") == 1)
	{
		ft_printf(fd, "[bench] disorder: %f\n", bench->disorder);
		ft_printf(fd, "[bench] strategy: %s\n", bench->strategy);
		ft_printf(fd, "[bench] total_ops: %d\n", bench->total_ops);
		ft_printf(fd, "[bench] sa:	%d	sb:	%d ss:	%d	pa:	%d	pb:	%d\n", bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
		ft_printf(fd, "[bench] ra:	%d	rb:	%d rr:	%d	rra:	%d	", bench->ra, bench->rb, bench->rr, bench->rra);
		ft_printf(fd, "rrb:	%u	rrr:	%d\n", bench->rrb, bench->rrr);
	}
	return ;
}
