/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compte_disorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:31:36 by andriraz          #+#    #+#             */
/*   Updated: 2026/03/29 14:35:37 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*creat_tab(t_stack *a)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	tmp = a->top;
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (arr);
}

static double	count_mistake(int *arr, int size)
{
	double	mistake;
	double	total_pairs;
	int		i;
	int		j;

	mistake = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (arr[i] > arr[j])
				mistake += 1;
			j++;
		}
		i++;
	}
	return (mistake / total_pairs);
}

double	count_disorder(t_stack *a)
{
	int		*arr;
	double	result;

	if (a->size < 2)
		return (0.0);
	arr = creat_tab(a);
	if (!arr)
		return (0.0);
	result = count_mistake(arr, a->size);
	free(arr);
	return (result);
}
