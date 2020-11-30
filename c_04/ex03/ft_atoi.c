/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:32:10 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 20:26:53 by teom             ###   ########.fr       */
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
	minus_num = 1;
	while (*str == '\t' ||
			*str == '\n' ||
			*str == '\v' ||
			*str == '\f' ||
			*str == '\r' ||
			*str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus_num *= -1;
		str++;
	}
	while (it_is_num(*str))
	{
		val_atoi *= 10;
		val_atoi += (int)*str - '0';
		str++;
	}
	return (val_atoi * minus_num);
}
