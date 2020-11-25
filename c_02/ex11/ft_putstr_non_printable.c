/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:39:29 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 16:26:18 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			it_is_printable(unsigned char c)
{
	if (' ' <= c && c <= '~')
	{
		return (1);
	}
	return (0);
}

char		to_hex(unsigned char c)
{
	c = c + '0';
	if (c > '9')
	{
		return (c + 39);
	}
	return (c);
}

void		print_hex(unsigned char c)
{
	char hex1;
	char hex2;

	write(1, "\\", 2);
	hex1 = (int)c / 16;
	hex2 = (int)c % 16;
	ft_putchar(to_hex(hex1));
	ft_putchar(to_hex(hex2));
}

void		ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	*pmt;

	index = 0;
	pmt = (unsigned char*)str;
	while (pmt[index])
	{
		if (!it_is_printable(pmt[index]))
		{
			print_hex(pmt[index]);
		}
		else
		{
			ft_putchar(pmt[index]);
		}
		index++;
	}
}
