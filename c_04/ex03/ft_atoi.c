/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:32:10 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 05:18:50 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		it_is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int minus_num;
	int val_atoi;

	val_atoi = 0;
	minus_num = 0;
	while (*str)
	{
		if (*str == 45)
			minus_num++;
		if (it_is_num(*str))
		{
			while (it_is_num(*str))
			{
				val_atoi = (val_atoi * 10) + (*str - '0');
				str++;
			}
			if (minus_num % 2)
				return (-1 * val_atoi);
			else
				return (val_atoi);
		}
		str++;
	}
	return (0);
}
