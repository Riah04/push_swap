/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:59:21 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/28 13:40:00 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_bezero(char *str, size_t n)
{
	int i = 0;

	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return(str);
}

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

	i = 0;
	j = 0;
	if (!str || !str_2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_len(str) + ft_len(str_2) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	while (str_2[j])
	{
		result[i + j] = str_2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_dup(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_len(str);
	res = malloc(sizeof(char) * len + 1);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_sub(char *str, int start, int len)
{
	char	*res;
	int		i;

	if (start >= len)
		return (ft_dup(""));
	if (len >= ft_len(str) - start)
		len = ft_len(str) - start;
	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (str[start] != '\0' && len > start)
	{
		res[i] = str[start];
		i++;
		start++;
	}
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
	while (i < len)
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}
