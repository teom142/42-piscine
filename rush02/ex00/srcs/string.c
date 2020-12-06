/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:38:50 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:38:50 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int				chk_number(char *num, char *line)
{
	while ((*line != ':' && *line != ' ') || *num)
	{
		if (*num != *line)
			return (0);
		line++;
		num++;
	}
	return (1);
}

void			ft_charcat(char *dest, char c)
{
	while (*dest)
		dest++;
	*(dest++) = c;
	*dest = 0;
}

int				it_is_printable(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

unsigned int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			ft_putline(char *line)
{
	while (*line != ':')
		line++;
	while (*line == ' ' || *line == ':')
		line++;
	while (*line)
	{
		if (it_is_printable(*line))
			write(1, line, 1);
		line++;
	}
}
