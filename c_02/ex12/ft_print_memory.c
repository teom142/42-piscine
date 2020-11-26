/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:43:40 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 19:39:33 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex;
char g_str[16];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_addr(unsigned long long addr, unsigned int cnt)
{
	if (!addr)
	{
		while (cnt++ < 16)
		{
			ft_putchar('0');
		}
		return ;
	}
	print_addr(addr / 16, cnt + 1);
	ft_putchar(g_hex[addr % 16]);
}

void	char_to_hex(unsigned char *ptr, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		if (' ' <= ptr[i] && ptr[i] <= '~')
			g_str[i] = ptr[i];
		else
			g_str[i] = '.';
		ft_putchar(g_hex[(int)ptr[i] / 16]);
		ft_putchar(g_hex[(int)ptr[i] % 16]);
		++i;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		write(1, "  ", 2);
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned char	*curr_add;

	g_hex = "0123456789abcdef";
	i = 0;
	while (size)
	{
		if (size > 16)
			len = 16;
		else
			len = size;
		curr_add = (unsigned char*)addr + i;
		print_addr((unsigned long long)curr_add, 0);
		ft_putchar(':');
		char_to_hex(curr_add, len);
		ft_putchar(' ');
		write(1, g_str, len);
		ft_putchar('\n');
		size -= len;
		i += 16;
	}
	return (addr);
}
