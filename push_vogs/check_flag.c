/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:25:50 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/06 16:27:39 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_flag(int argc, char **argv, char *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], flag) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}
