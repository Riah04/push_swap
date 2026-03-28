/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:51:24 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/28 16:59:06 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(int nb)
{
	int	count;

	if (nb <= 0 && nb >= 9)
		return (1);
	while (nb != 0)
	{
		count++;
		nb / 10;
	}
	return (count);
}

static int	ft_max(t_list *lst)
{
	int		max;
	t_list	tmp;

	while (lst->next)
	{
		if (lst->value < lst->next->next)
			tmp = lst->value;
		lst->next;
	}
	return (max);
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int	count;

	while ()
	{
		
	}
}
