/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:37:05 by andriraz          #+#    #+#             */
/*   Updated: 2026/04/08 16:06:54 by nmariah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include "printf.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct t_stack
{
	int				size;
	t_list			*top;
	t_list			*bottom;
}					t_stack;

typedef struct s_flag
{
	int				bench;
	int				simple;
	int				medium;
	int				complexe;
	int				adaptive;
	int 			flag;
}					t_flags;

typedef struct t_bench
{
	double			disorder;
	char			*strategy;
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
	unsigned int	total_ops;
}					t_bench;

long				ft_atol(const char *nptr);
t_stack				*init_stack(void);
t_list				*ft_lstnew(int val);
void				stack_add_back(t_stack *stack, t_list *noeud);
char				**ft_split(const char *s, char c);
int					parse_args(int argc, char **argv, t_stack *a);
void				sa(t_stack *a, t_bench *bench);
void				sb(t_stack *b, t_bench *bench);
void				ss(t_stack *a, t_stack *b, t_bench *bench);
void				ra(t_stack *a, t_bench *bench);
void				rb(t_stack *b, t_bench *bench);
void				rr(t_stack *a, t_stack *b, t_bench *bench);
void				pa(t_stack *a, t_stack *b, t_bench *bench);
void				pb(t_stack *a, t_stack *b, t_bench *bench);
void				rra(t_stack *a, t_bench *bench);
void				rrb(t_stack *b, t_bench *bench);
void				rrr(t_stack *a, t_stack *b, t_bench *bench);
double				count_disorder(t_stack *a);
void				simple_sort(t_stack *a, t_stack *b, t_bench *bench);
int					ft_sqrt(int nb);
void				medium_sort(t_stack *a, t_stack *b, t_bench *bench);
int					get_max_pos(t_stack *s);
int					get_max(t_stack *s);
void				free_split(char **arr);
void				ft_radix(t_stack *a, t_stack *b, t_bench *bench);
int					ft_strcmp(char *s1, char *s2);
int					is_flag(char *str);
int					has_flag(char **argv, int argc, char *flag);
void				ft_bench(char **argv, int argc, t_bench *bench, int fd);

void				ft_init_bench(t_bench *bench);
int					ft_putnbr_u_fd(unsigned int i, int fd);
int					ft_dig_count(unsigned int n);
int					ft_putchar_fd(char c, int fd);
void				ft_adaptive(t_stack *a, t_stack *b, char **argv, int argc, t_bench *bench);
int					ft_2d(double d, int fd);

#endif
