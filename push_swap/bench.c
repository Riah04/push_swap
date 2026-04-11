/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:23:42 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/09 21:52:02 by andriraz         ###   ########.fr       */
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
	bench->ra = 0;
	bench->rb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
}

void	ft_bench(t_bench *bench, int fd)
{
	ft_printf(fd, "[bench] disorder: ");
	ft_2d(bench->disorder, fd);
	ft_printf(fd, "%%");
	ft_printf(fd, "\n[bench] strategy: %s\n", bench->strategy);
	ft_printf(fd, "[bench] total_ops: %d\n", bench->total_ops);
	ft_printf(fd, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf(fd, "[bench] ra: %d rb: %d rr: %d rra: %d ", bench->ra, bench->rb,
		bench->rr, bench->rra);
	ft_printf(fd, "rrb: %u rrr: %d\n", bench->rrb, bench->rrr);
	return ;
}
