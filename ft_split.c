/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:32:22 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/10 16:13:20 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *str, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static unsigned int	len_word(const char *str, int i, char c)
{
	unsigned int	start;

	start = i;
	while (str[i] && str[i] != c)
		i++;
	return (i - start);
}

static void	free_tab(char **tab, int k)
{
	while (k >= 0)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
}

static char	*word_allocation(const char *str, int *i, char c)
{
	int		len;
	char	*word;
	int		j;

	j = 0;
	while (str[*i] == c)
		(*i)++;
	len = len_word(str, *i, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (j < len)
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	words = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (k < words)
	{
		result[k] = word_allocation(s, &i, c);
		if (!result[k])
		{
			free_tab(result, k - 1);
			return (NULL);
		}
		k++;
	}
	result[k] = NULL;
	return (result);
}
