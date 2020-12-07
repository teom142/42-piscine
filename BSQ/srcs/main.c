/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:28:17 by teom              #+#    #+#             */
/*   Updated: 2020/12/07 19:34:21 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	g_size;
unsigned int	g_row;
unsigned int	g_col;
unsigned int	g_sym_size;
char			*g_symbol;
char			**g_map;

#include <stdio.h>
void	bsq(char *argv)//, int argc)
{
	int		fd;
	int		rd_suc;
	char	c;

	g_sym_size = get_sym_size(argv);
	g_symbol = (char*)malloc(g_sym_size + 1);
	/*
	if (argc != 1)
		fd = open(argv, O_RDONLY);
	else
		fd = 0;
		*/
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_putstr(ERR_MSG);
	else
	{
		rd_suc = read(fd, &c, 1);
		while (rd_suc && c != '\n')
		{
			ft_charcat(g_symbol, c);
			rd_suc = read(fd, &c, 1);
		}
		g_col = count_col(g_symbol);
		g_symbol += g_sym_size - 4;
		g_row = (g_size - g_sym_size) / g_col - 1;
		g_map = (char**)malloc(sizeof(char*) * g_col);
		get_map(g_map, fd);
		close(fd);
	}
}

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		g_size = get_size(fd);
		bsq(argv[1]);//, argc);
		find_square();
	}
}
