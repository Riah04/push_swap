/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:08:03 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/09 20:08:05 by andriraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *s)
{
	t_list	*tmp;
	int		max;

	tmp = s->top;
	max = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_max_pos(t_stack *s)
{
	t_list	*tmp;
	int		position;
	int		max;
	int		i;

	max = get_max(s);
	tmp = s->top;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value == max)
			position = i;
		i++;
		tmp = tmp->next;
	}
	return (position);
}
