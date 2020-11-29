/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:53:25 by teom              #+#    #+#             */
/*   Updated: 2020/11/29 23:54:18 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

extern void		f_start_dfs(int box[4][4], int col_row[4][4]);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_box(int box[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(box[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	fill_box(int col_row[4][4], int box[4][4])
{
	int coro_i;
	int coro_j;

	coro_i = 0;
	while (coro_i < 4)
	{
		coro_j = 0;
		while (coro_j < 4)
		{
			box[coro_i][coro_j] = 0;
			coro_j++;
		}
		coro_i++;
	}
	f_start_dfs(box, col_row);
	display_box(box);
}

int		main(int argc, char *argv[])
{
	int line[4][4];
	int box[4][4];
	int cnt;
	int i;
	int j;

	i = 0;
	cnt = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[i][j] = (int)argv[1][cnt] - '0';
			cnt += 2;
			j++;
		}
		i++;
	}
	fill_box(line, box);
}
