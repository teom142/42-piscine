/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:11:02 by teom              #+#    #+#             */
/*   Updated: 2020/11/21 18:21:01 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combo(void)
{
	char num1;
	char num2;
	char num3;

	num1 = '0' - 1;
	while (++num1 <= '7')
	{
		num2 = num1;
		while (++num2 <= '8')
		{
			num3 = num2;
			while (++num3 <= '9')
			{
				if (num1 != '0' || num2 != '1' || num3 != '2')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ft_putchar(num1);
				ft_putchar(num2);
				ft_putchar(num3);
			}
		}
	}
}
