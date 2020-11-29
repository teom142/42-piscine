/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:46:47 by teom              #+#    #+#             */
/*   Updated: 2020/11/29 23:48:36 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_i;
int		g_j;

int		chk_n(int *line, int rev)
{
	int		i;
	int		pivot;
	int		cnt;

	if (rev)
		i = 3;
	else
		i = 0;
	cnt = 1;
	pivot = line[i];
	while (i < 4 && i >= 0)
	{
		if (line[i] > pivot)
		{
			pivot = line[i];
			cnt++;
		}
		if (rev)
			i--;
		else
			i++;
	}
	return (cnt);
}

int		it_is_overlap(int box_i, int box_j, int box[4][4])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (box[box_i][box_j] == box[i][box_j] && box_i != i)
			return (0);
		if (box[box_i][box_j] == box[box_i][i] && box_j != i)
			return (0);
		i++;
	}
	return (1);
}

int		back_tracking(int box[4][4], int cr[4][4], int cnt)
{
	int c_l[4];
	int col_i;

	if (cnt > 4)
		return (1);
	if (g_j > 3)
	{
		if (cr[2][g_i] != chk_n(box[g_i], 0))
		{
			if (cr[3][g_i] != chk_n(box[g_i], 1))
				return (1);
		}
	}
	if (g_i == 3 && it_is_overlap(g_i, g_j - 1, box))
	{
		col_i = 0;
		while (col_i < 4)
		{
			c_l[col_i] = box[col_i][g_j - 1];
			col_i++;
		}
		if (cr[0][g_j - 1] != chk_n(c_l, 0) || cr[1][g_j - 1] != chk_n(c_l, 1))
			return (1);
	}
	return (0);
}

void	do_back_track(int box[4][4])
{
	box[g_i][g_j] = 0;
	g_j--;
	if (g_j < 0)
	{
		g_j = 3;
		g_i--;
	}
	while (box[g_i][g_j] >= 4)
	{
		box[g_i][g_j] = 0;
		g_j--;
		if (g_j < 0 && g_i >= 1)
		{
			g_j = 3;
			g_i--;
		}
	}
}

void	f_start_dfs(int box[4][4], int col_row[4][4])
{
	int cnt;

	cnt = 1;
	g_i = 0;
	while (g_i < 4)
	{
		g_j = 0;
		while (g_j < 4)
		{
			box[g_i][g_j] = cnt;
			if (it_is_overlap(g_i, g_j, box))
			{
				g_j++;
				cnt = 1;
			}
			else
				cnt++;
			if (back_tracking(box, col_row, cnt))
			{
				do_back_track(box);
				cnt = box[g_i][g_j] + 1;
			}
		}
		g_i++;
	}
}
