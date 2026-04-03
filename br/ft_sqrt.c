#include "push_swap.h"

static int	ft_recusive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recusive_power(nb, power - 1));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb > 0)
	{
		while (i <= 46360)
		{
			if (ft_recusive_power(i, 2) >= nb)
				return (i);
			i++;
		}
	}
	return (0);
}
