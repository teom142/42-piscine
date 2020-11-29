/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:36:17 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 05:18:58 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cal_base(int curr_n, char *base, int base_len)
{
	if (curr_n >= base_len)
		cal_base(curr_n / base_len, base, base_len);
	write(1, &base[curr_n % base_len], 1);
}

int		exception_base(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	base_len = exception_base(base);
	if (base_len <= 1)
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		cal_base(-1 * (nbr / base_len), base, base_len);
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
