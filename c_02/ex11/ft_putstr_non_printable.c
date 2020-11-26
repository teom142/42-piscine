/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:39:29 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 20:52:27 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			it_is_printable(char c)
{
	if (' ' <= c && c <= '~')
	{
		return (1);
	}
	return (0);
}

void		print_hex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 2);
	ft_putchar(hex[(int)c / 16]);
	ft_putchar(hex[(int)c % 16]);
}

void		ft_putstr_non_printable(char *str)
{
	int				index;

	index = 0;
	while (str[index])
	{
		if (!it_is_printable(str[index]))
		{
			print_hex(str[index]);
		}
		else
		{
			ft_putchar(str[index]);
		}
		index++;
	}
}
