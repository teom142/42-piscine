#include <unistd.h>

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


void	cal_base(int curr_n, char *base, int base_len)
{
	if (curr_n >= base_len)
		cal_base(curr_n / base_len, base, base_len);
	write(1, &base[curr_n % base_len], 1);
}


void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	base_len = str_len(base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		cal_base(-1 * (nbr / str_len(base)), base, base_len);
		write(1, &base[-1 * (nbr % base_len)], 1);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	cal_base(nbr, base, base_len);
}	
