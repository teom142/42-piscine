#include "bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_charcat(char *str, char c)
{
	while (*str)
		str++;
	*(str++) = c;
	*str = 0;
}
