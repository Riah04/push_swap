#include "push_swap.h"
#include <stdio.h>
// CETTE FONCTION N'EST QUE POUR LE TEST
void	print_stacks(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	write(1, "A: ", 3);
	tmp = a->top;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	write(1, "B: ", 3);
	tmp = b->top;
	while (tmp)
	{
		//write(1, tmp->value, 1);
		// POUR QUE CA FONCTION IL FAUT QUE LE tmp SOIT CONVERTIE PAR ft_itoa
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
	write(1, "\n\n", 2);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*tmp;
	t_list	*tmp1;

	if (argc < 2)
		return (1);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	medium_sort(a, b);
	print_stacks(a, b);
	return (0);
}
