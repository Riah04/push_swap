/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:25:50 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/07 17:01:37 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *str, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static void	free_tab(char **tab, int k)
{
	int	j;

	j = 0;
	while (k > j)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

int	has_flag(char **argv, int argc, char *flag)
{
	int		count;
	char	**split;
	int		k;
	int		j;

	k = 0;
	count = 0;
	while (argc > k)
	{
		j = 0;
		count = count_word(argv[k], ' ');
		split = ft_split(argv[k], ' ');
		while (j < count)
		{
			if (ft_strcmp(split[j], flag) == 0)
				return (free_tab(split, count), 1);
			j++;
		}
		free_tab(split, count);
		k++;
	}
	return (0);
}
