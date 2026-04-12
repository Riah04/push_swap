/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:43:40 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/10 10:58:30 by nmariah          ###   ########.fr       */
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

void	init_flag(t_flags *f)
{
	if (!f)
		return ;
	f->adaptive = 0;
	f->bench = 0;
	f->medium = 0;
	f->simple = 0;
	f->complex = 0;
}

int	ft_too_many_flags(t_flags *flags)
{
	if (flags->simple + flags->medium + flags->adaptive + flags->complex > 1)
		return (0);
	return (1);
}

int	is_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	return (0);
}
