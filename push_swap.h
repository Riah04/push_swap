/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:05 by andriraz          #+#    #+#             */
/*   Updated: 2026/03/25 11:37:07 by andriraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct t_stack
{
	int				size;
	t_list			*top;
	t_list			*bottom;
}					t_stack;
long				ft_atol(const char *nptr);
t_stack				*init_stack(void);
t_list				*ft_lstnew(int val);
void				stack_add_back(t_stack *stack, t_list *noeud);
char				**ft_split(const char *s, char c);
int					parse_args(int argc, char **argv, t_stack *a);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
double				compte_disorder(t_stack *a);
void				simple_sort(t_stack *a, t_stack *b);
int ft_sqrt(int nb);
void	medium_sort(t_stack *a, t_stack *b);

#endif
