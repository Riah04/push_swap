/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 08:15:05 by nmariah           #+#    #+#             */
/*   Updated: 2026/04/12 15:17:59 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
#include <stdlib.h>
#include "get_next_line_bonus.h"
# include "../push_swap.h"

void	rra_b(t_stack *a);
void	rrb_b(t_stack *b);
void	rrr_b(t_stack *a, t_stack *b);
void	ra_b(t_stack *a);
void	rb_b(t_stack *b);
void	rr_b(t_stack *a, t_stack *b);
void	sa_b(t_stack *a);
void	sb_b(t_stack *b);
void	ss_b(t_stack *a, t_stack *b);
void	pa_b(t_stack *a, t_stack *b);
void	pb_b(t_stack *a, t_stack *b);
t_stack	*init_stack(void);
int		ft_ops(t_stack *a, t_stack *b, char *line);
int	parse_args_bonus(int argc, char **argv, t_stack *a);

#endif