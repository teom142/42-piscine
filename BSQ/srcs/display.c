/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:39:50 by teom              #+#    #+#             */
/*   Updated: 2020/12/09 20:02:07 by soojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern int		g_row;
extern char		**g_map;
extern char		*g_symbol;
extern char		g_empty;
extern char		g_obstacle;
extern char		g_fill;
extern int		g_free;

void			disp_map(char **map, int col)
{
	int		i;

	i = 0;
	while (i < col)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}

int				count_col(char *symbol)
{
	int		ret;

	ret = 0;
	while (*symbol)
	{
		if (*symbol < '0' || *symbol > '9')
			return (0);
		ret *= 10;
		ret += (int)*symbol - '0';
		symbol++;
	}
	return (ret);
}

void			free_map(int col)
{
	int		i;

	i = 0;
	if (g_free)
		free(g_symbol);
	if (g_free == 2)
	{
		while (i < col)
			free(g_map[i++]);
		free(g_map);
	}
}
