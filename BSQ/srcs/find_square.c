/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:27:05 by teom              #+#    #+#             */
/*   Updated: 2020/12/09 10:38:41 by soojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern int		g_row;
extern int		g_col;
extern char		**g_map;
extern char		g_empty;
extern char		g_obstacle;
extern char		g_fill;
int				g_max_square;
int				g_square_i;
int				g_square_j;

int				square_possible(int i, int j, int next_i, int next_j)
{
	while (i <= next_i)
	{
		if (next_i == g_col || next_j == g_row)
			return (0);
		if (g_map[i][next_j] == g_obstacle)
			return (0);
		if (g_map[next_i][j] == g_obstacle)
			return (0);
		i++;
		j++;
	}
	return (1);
}

unsigned int	curr_max_square(int i, int j)
{
	int	next_i;
	int	next_j;
	int	square_size;

	next_i = i;
	next_j = j;
	square_size = 0;
	while (square_possible(i, j, next_i, next_j))
	{
		next_i++;
		next_j++;
		square_size++;
	}
	return (square_size);
}

void			fill_box(void)
{
	int	i;
	int	j;

	i = g_square_i;
	while (i < g_square_i + g_max_square)
	{
		j = g_square_j;
		while (j < g_square_j + g_max_square)
		{
			g_map[i][j] = g_fill;
			j++;
		}
		i++;
	}
}

void			find_square(void)
{
	int	i;
	int	j;
	int	curr_square;

	i = 0;
	g_max_square = 0;
	while (i < g_col)
	{
		j = 0;
		while (j < g_row)
		{
			curr_square = curr_max_square(i, j);
			if (curr_square > g_max_square)
			{
				g_square_i = i;
				g_square_j = j;
				g_max_square = curr_square;
			}
			j++;
		}
		i++;
	}
	fill_box();
}
