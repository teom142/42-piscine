/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:32:04 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 10:55:59 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*g_base_to;
int			ft_atoi_base(char *str, char *base);

int			chk_base_to(void)
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
	while (g_base_to[len])
	{
		if (g_base_to[len] == '+' ||
				g_base_to[len] == '-' ||
				base_over[(int)g_base_to[len]])
			return (0);
		base_over[(int)g_base_to[len]] = 1;
		len++;
	}
	return (len);
}

int			ret_strlen(int nbr, int base_len)
{
	int		ret_len;

	ret_len = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
	{
		ret_len += 2;
		nbr /= -1 * base_len;
	}
	while (nbr >= base_len)
	{
		nbr /= base_len;
		ret_len++;
	}
	return (ret_len + 1);
}

void		cal_base(char *dest, int num, int base_len, int i)
{
	if (num < 0)
	{
		num *= -1;
		dest[0] = '-';
	}
	if (num >= base_len)
		cal_base(dest, num / base_len, base_len, i - 1);
	dest[i] = g_base_to[num % base_len];
}

void		nega_max(char *dest, int nbr, int base_len, int str_len)
{
	dest[0] = '-';
	cal_base(dest, -1 * (nbr / base_len), base_len, str_len - 1);
	dest[str_len] = g_base_to[nbr % base_len];
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_number;
	int		base_to_len;
	char	*ret_str;
	int		ret_len;

	g_base_to = base_to;
	from_number = ft_atoi_base(nbr, base_from);
	base_to_len = chk_base_to();
	if (!from_number)
		return (0);
	if (base_to_len <= 1)
		return (0);
	ret_len = ret_strlen(from_number, base_to_len);
	ret_str = (char*)malloc(ret_len);
	if (from_number == -2147483648)
	{
		nega_max(ret_str, from_number, base_to_len, ret_len - 1);
		ret_str[ret_len] = 0;
		return (ret_str);
	}
	cal_base(ret_str, from_number, base_to_len, ret_len - 1);
	ret_str[ret_len] = 0;
	return (ret_str);
}
