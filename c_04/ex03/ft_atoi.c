/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:32:10 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 15:40:33 by teom             ###   ########.fr       */
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
	int val_end;

	val_end = 1;
	val_atoi = 0;
	minus_num = 1;
	while (*str)
	{
		if (it_is_num(*str) && val_end)
		{
			while (it_is_num(*str))
			{
				val_atoi = (val_atoi * 10) + (*str - '0');
				str++;
			}
			val_end = 0;
		}
		if(*str == '-')
			minus_num *= -1;
		str++;
	}
	return (val_atoi * minus_num);
}

#include <stdio.h>
int		main(int argc, char *argv[])
{
	printf("%d\n",ft_atoi(argv[1]));
}
