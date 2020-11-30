/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_queens_puzzle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:23:47 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 13:32:10 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int 	g_chess[10];
int		g_pos_case;

int		back_track(int index, int val)
{
	int j;

	j = 0;
	while (j < index)
	{
		if (g_chess[j] == val)
			return (0);
		if (g_chess[j] == val + index - j)
			return (0);
		if (g_chess[j] == val - index + j)
			return (0);
		j++;	
	}
	return (1);
}

void	chess_dfs(int index)
{
	int i;
	int j;
	char c;

	if (index == 9)
	{
		j = 0;
		while (j < 10)
		{
			c = g_chess[j] + '0';
			write(1, &c, 1);
			j++;
		}
		g_pos_case++;
		write(1,"\n",1);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		g_chess[index+1] = i;
		if (back_track(index + 1,g_chess[index + 1]))
			chess_dfs(index + 1);
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;

	g_pos_case = 0;
	i = 0;
	while (i < 10)
	{
		g_chess[0] = i;
		chess_dfs(0);
		i++;
	}
	return (g_pos_case);
}
