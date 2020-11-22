/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:11:12 by teom              #+#    #+#             */
/*   Updated: 2020/11/21 13:19:23 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = -1;
	while (++num1 <= 99)
	{
		num2 = num1;
		while (++num2 <= 99)
		{
			if (num1 != 0 || num2 != 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar(num1 / 10 + '0');
			ft_putchar(num1 % 10 + '0');
			ft_putchar(' ');
			ft_putchar(num2 / 10 + '0');
			ft_putchar(num2 % 10 + '0');
		}
	}
}
