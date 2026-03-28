/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:44:02 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/27 01:31:23 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	int i = 0;
	while (1)
	{
		char *ligne = get_next_line(fd);
	//char *s = get_next_line(fd);
	//char *s1 = get_next_line(fd);
		if (!ligne)
			return (0);
		printf("%s\n", ligne); //ligne2 = %s\n et ligne3 = %s \n ", ligne, s, s1);
		free(ligne);
	}
	//free(s);
	/*char *ligne = ft_read(fd);
	printf("ligne1 = %s\n", ligne);*/
	close(fd);
	return (0);
}
