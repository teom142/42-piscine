/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:27:05 by teom              #+#    #+#             */
/*   Updated: 2020/12/07 20:39:36 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern unsigned int		g_row;
extern unsigned int		g_col;
extern char				**g_map;
extern char				*g_symbol;
unsigned int			g_max_square;
int						g_square_i;
int						g_square_j;

int				square_possible(int i, int j, int next_i, int next_j)
{
	int		size;

	while (i <= next_i)
	{
		if(g_map[i][next_j] == g_symbol[2])
			return (0);
		if(g_map[next_j][j] == g_symbol[2])
			return (0);
		i++;
		j++;
	}
	return (1);
}

unsigned int	curr_max_square(int i, int j)
{
	int				next_i;
	int				next_j;
	unsigned int	square_size;

	next_i = i;
	next_j = j;
	square_size = 1;
	while (square_possible(i, j, next_i, next_j))
	{
		next_i++;
		next_j++;
		square_size++;
	}
	return (square_size);
}

void			find_square()
{
	int				i;
	int				j;
	unsigned int	curr_square;

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
}
