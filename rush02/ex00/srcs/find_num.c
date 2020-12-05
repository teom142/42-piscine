#include "rush02.h"

int	g_thou;
int	g_init;

unsigned long long	ft_power(int nb, int power)
{
	unsigned long long	ret;

	ret = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 0)
		ret *= nb;
	return (ret);
}



void			find_num(char *str)
{
	*str = 0;	
}
