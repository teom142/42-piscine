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

int		g_size;
int		g_row;
int		g_col;
int		g_sym_size;
char			*g_symbol;
char			**g_map;
char		g_empty;
char		g_obstacle;
char		g_fill;
/*
void	bsq(char *argv)
{
	int		fd;
	int		rd_suc;
	char	c;

	g_sym_size = get_sym_size(argv);
	g_symbol = (char*)malloc(g_sym_size + 1);
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
*/
int	main(int argc, char *argv[])
{
	int fd;

	if (argc == 1)
		fd = 0;
	if (argc == 2)
		fd = open(argv[1],O_RDONLY);
	read_map(fd);
	close(fd);
	find_square();
	disp_map(g_map, g_col);
}
