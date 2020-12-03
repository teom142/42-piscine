#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);

int		chk_base_to(char *base)
{
	int		base_over[256];
	int		len;

	len = 0;
	while (len < 256)
	{
		base_over[len] = 0;
		len++;
	}
	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-' || base_over[(int)base[len]])
			return (0);
		base_over[(int)base[len]] = 1;
		len++;
	}
	return (len);
}

int		ret_strlen(int nbr, int base_len)
{
	int ret_len;

	ret_len = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
		ret_len++;
	while (nbr < base_len)
	{
		nbr /= base_len;
		ret_len++;
	}
	return (ret_len);
}

void	cal_base(char *dest, int num, char *base, int base_len, int i)
{
	if (num >= base_len)
		cal_base(dest, num / base_len, base, base_len, i+1);
	dest[i] = base[num % base_len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_number;
	int		base_to_len;
	char	*ret_str;
	int		ret_len;

	from_number = ft_atoi_base(nbr, base_from);
	base_to_len = chk_base_to(base_to);
	if (!from_number)
		return (0);
	if (chk_base_to <= 1)
		return (0);
	ret_len = ret_strlen(from_number, base_to_len);
	ret_str = (char*)malloc(ret_len + 1);
	cal_base(ret_str, from_number, base_to, base_to_len, 0);
	return (ret_str);
}
