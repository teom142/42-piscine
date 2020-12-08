/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:39:50 by teom              #+#    #+#             */
/*   Updated: 2020/12/07 20:34:22 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern unsigned int	g_row;

void			disp_map(char **map, unsigned int col)
{
	unsigned int	i;

	i = 0;
	while (i < col)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}
/*
void			get_map(char **map, int fd)
{
	int		i;
	int		j;
	int		rd_suc;
	char	c;

	i = -1;
	j = 0;
	rd_suc = read(fd, &c, 1);
	while (rd_suc)
	{
		if (j % g_row == 0 && c != '\n')
		{
			i++;
			map[i] = (char *)malloc(g_row + 1);
			map[i][0] = 0;
		}
		if (c != '\n')
		{
			ft_charcat(map[i], c);
			j++;
		}
		rd_suc = read(fd, &c, 1);
	}
}*/
