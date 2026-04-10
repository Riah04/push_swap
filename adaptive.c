/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:05:10 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/10 11:06:07 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b)
		return ;
	if (count_disorder(a) < 0.2)
	{
		simple_sort(a, b, bench);
		bench->strategy = "Adaptive / O(n²)";
	}
	else if (count_disorder(a) >= 0.2 && count_disorder(a) < 0.5)
	{
		medium_sort(a, b, bench);
		bench->strategy = "Adaptive / O(n√n)";
	}
	else
	{
		ft_radix(a, b, bench);
		bench->strategy = "Adaptive / O(n log n)";
	}
}
