/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:05:10 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/07 16:16:47 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s, char *s1)
{
	int	i;

	i = 0;
	while (s[i] || s1[i])
	{
		if (s[i] != s1[i])
			return (s1[i] - s1[i]);
		i++;
	}
	return (0);
}

void	ft_adaptive(t_stack *a, t_stack *b, char **argv, t_bench *bench, int argc)
{
	if (!a || !b || !argv)
		return ;
	else if (has_flag(argc, argv, "--adaptive"))
	{
		if (count_disorder(a, bench) < 0.2)
			simple_sort(a, b, bench);
		else if (count_disorder(a, bench) >= 0.2 && count_disorder(a, bench) < 0.5)
			medium_sort(a, b, bench);
		else if (count_disorder(a, bench) > 0.5)
			ft_radix(a, b, bench);
	}
	else
		ft_adaptive(a, b, argv, bench, argc);
}
