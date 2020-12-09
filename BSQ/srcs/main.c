/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:28:17 by teom              #+#    #+#             */
/*   Updated: 2020/12/09 18:05:16 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			g_size;
int			g_row;
int			g_col;
int			g_sym_size;
char		*g_symbol;
char		**g_map;
char		g_empty;
char		g_obstacle;
char		g_fill;
int			g_free;

void	bsq(int fd)
{
	g_free = 0;
	if (read_map(fd, -1))
	{
		write(2, ERR_MSG, 10);
		close(fd);
		free_map(g_col);
		return ;
	}
	close(fd);
	find_square();
	disp_map(g_map, g_col);
	free_map(g_col);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;

	i = 0;
	if (argc == 1)
	{
		fd = 0;
		bsq(fd);
		return (0);
	}
	else
	{
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				write(2, ERR_MSG, 10);
				continue ;
			}
			bsq(fd);
		}
	}
	return (0);
}
