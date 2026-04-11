/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 09:15:36 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/06 10:09:02 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_join(char *str, char *str_2)
{
	char	*result;
	int		i;
	int		j;

	if (!str && !str_2)
		return (NULL);
	i = 0;
	j = 0;
	if (!str)
		return (ft_substr(str_2, 0, ft_len(str_2)));
	if (!str_2)
		return (ft_substr(str, 0, ft_len(str)));
	result = malloc(sizeof(char) * (ft_len(str) + ft_len(str_2) + 1));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	while (str_2[j] != '\0')
		result[i++] = str_2[j++];
	result[i++] = '\0';
	return (free(str), result);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	if (start >= ft_len(str))
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (len >= ft_len(str) - start)
		len = ft_len(str) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < len)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

int	ft_strsrch(char *str, char a)
{
	int		i;
	int		len;

	if (!str)
		return (-1);
	len = ft_len(str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}
