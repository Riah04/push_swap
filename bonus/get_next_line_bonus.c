/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 09:15:31 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/06 10:32:33 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *stash)
{
	char	*tmp;
	int		count_1;

	count_1 = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (free(stash), NULL);
	while (ft_strsrch(stash, '\n') == -1)
	{
		count_1 = read(fd, tmp, BUFFER_SIZE);
		if (count_1 < 0)
			return (free(tmp), free(stash), NULL);
		if (count_1 == 0)
			return (free(tmp), stash);
		tmp[count_1] = '\0';
		stash = ft_join(stash, tmp);
		if (!stash)
			return (free(tmp), NULL);
	}
	free(tmp);
	if (!stash || stash[0] == '\0')
		return (free(stash), NULL);
	return (stash);
}

static char	*ft_extract_line(char *stash)
{
	int		len;
	char	*dup;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	dup = ft_substr(stash, 0, len);
	if (!dup)
		return (NULL);
	return (dup);
}

static char	*ft_update_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	new_stash = ft_substr(stash, i, ft_len(stash + i));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	if (new_stash && new_stash[0] == '\0')
		return (free(new_stash), NULL);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_update_stash(stash[fd]);
	return (line);
}
