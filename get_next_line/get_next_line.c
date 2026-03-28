/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:40:17 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/28 17:03:55 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		count;
	char	*result;
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	result = malloc(1);
	result[0] = '\0';
	while (ft_strsrch(tmp, '\n') < 0)
	{
		count = read(fd, tmp, BUFFER_SIZE + 1);
		if (count == 0)
			return (free(tmp), result);
		if (count < 0)
			return (NULL);
		tmp[count] = '\0';
		free(result);
		result = ft_join(tmp, result);
	}
	return (result);
}

char	*ft_take(char *stash)
{
	char	*new;
	int		i;
	int		j;
	int		s_len;

	if (!stash)
		return (NULL);
	i = ft_strsrch(stash, '\n');
	j = ft_strsrch(stash, '\0');
	s_len = ft_len(stash);
	if (i)
		new = ft_sub(stash, 0, i);
	else if (j)
		new = ft_sub(stash, 0, j);
	return (free(stash), new);
}

char	*get_next_line(int fd)
{
	char		*line;
	const char	*stash;
	char		*got;

	stash = 
	return (line);
}