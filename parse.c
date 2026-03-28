/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/03/25 11:36:28 by andriraz          #+#    #+#             */
/*   Updated: 2026/03/25 11:36:28 by andriraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_number(char *str)
{
	int i;

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

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	**args;
	int		i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		if (!check_arg(args[i], a))
			return (0);
		i++;
	}
	return (1);
}
