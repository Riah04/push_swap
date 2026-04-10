/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 06:20:07 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/10 16:21:41 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_double(t_stack *stack, int val)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_arg(char *str, t_stack *a)
{
	long	x;

	if (is_flag(str))
		return (1);
	if (!is_number(str))
		return (0);
	x = ft_atol(str);
	if (x > INT_MAX || x < INT_MIN)
		return (0);
	if (is_double(a, (int)x))
		return (0);
	stack_add_back(a, ft_lstnew((int)x));
	return (1);
}

static int	parsing_arg(char *arg, t_stack *a)
{
	char	**args;
	int		i;

	args = ft_split(arg, ' ');
	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		if (!check_arg(args[i], a))
		{
			free_split(args);
			return (0);
		}
		i++;
	}
	free_split(args);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parsing_arg(argv[i], a))
			return (free_stack(a), 0);
		i++;
	}
	return (1);
}
