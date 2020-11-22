/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:35:23 by teom              #+#    #+#             */
/*   Updated: 2020/11/21 17:52:49 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_num[10];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(int n)
{
	int index;

	index = 0;
	while (index < n)
	{
		ft_putchar(g_num[index] + '0');
		index++;
	}
	if (g_num[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	array_assign(int n, int k)
{
	g_num[n - k - 1]++;
	while (k > 0)
	{
		g_num[n - k] = g_num[n - k - 1] + 1;
		k--;
	}
}

void	find_max_n(int n)
{
	int k;
	int assign_suc;

	assign_suc = 1;
	print_array(n);
	if (g_num[n - 1] < 9)
	{
		g_num[n - 1]++;
	}
	else
	{
		k = 0;
		while (assign_suc)
		{
			if (g_num[n - 1 - k] == 9 - k)
			{
				k++;
			}
			else
			{
				array_assign(n, k);
				assign_suc = 0;
			}
		}
	}
}

void	ft_print_combn(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		g_num[i] = i;
		i++;
	}
	while (g_num[0] < 10 - n)
	{
		find_max_n(n);
	}
	print_array(n);
}
