/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 10:06:26 by nmariah           #+#    #+#             */
/*   Updated: 2026/03/27 02:19:37 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_read(int fd);
int		ft_len(char *str);
char	*ft_cop(char *src, char *dst);
char	*ft_save(char *str);
int		ft_strsrch(char *str, char a);
char	*ft_sub(char *str, int start, int len);
char	*ft_join(char *str, char *str_2);
char	*ft_dup(char *str);
char *ft_bezero(char *str, size_t n);

#endif
