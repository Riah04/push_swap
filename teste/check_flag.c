#include "push_swap.h"

int	has_flag(int argc, char **argv, char *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], flag) == 0)
			return (1);
		i++;
	}
	return (0);
}

