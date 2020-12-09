/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojpark <soojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:32:35 by soojpark          #+#    #+#             */
/*   Updated: 2020/12/09 20:34:18 by soojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern char		*g_symbol;
extern char		**g_map;
extern char		g_empty;
extern char		g_obstacle;
extern char		g_fill;
extern int		g_col;
extern int		g_row;
extern int		g_free;

void	get_symbols(void)
{
	unsigned int sym_len;

	sym_len = ft_strlen(g_symbol);
	g_fill = g_symbol[sym_len - 1];
	g_obstacle = g_symbol[sym_len - 2];
	g_empty = g_symbol[sym_len - 3];
	g_symbol[sym_len - 3] = 0;
}

char	*expand_str(char *str, int size, char c)
{
	char *ret;

	str[size - 1] = c;
	str[size] = 0;
	if (!(ret = (char*)malloc(size + 2)))
		return (0);
	ft_strcpy(ret, str);
	free(str);
	return (ret);
}

int		read_symbol(int fd, int rd_suc, char c, int size)
{
	while (rd_suc && c != '\n')
	{
		if (!(g_symbol = expand_str(g_symbol, size, c)))
			return (1);
		rd_suc = read(fd, &c, 1);
		size++;
	}
	return (0);
}

int		read_map_sub(int fd, int rd_suc, int size, int chk_size)
{
	int		i;
	char	c;
	int		flag;

	i = -1;
	while (++i < g_col)
	{
		flag = 0;
		size = 1;
		if (!(g_map[i] = (char*)malloc(size + 1)))
			return (i + 1);
		rd_suc = read(fd, &c, 1);
		while (rd_suc && c != '\n')
		{
			if (c != g_empty && c != g_obstacle)
				flag++;
			if (!(g_map[i] = expand_str(g_map[i], size++, c)))
				return (i + 1);
			rd_suc = read(fd, &c, 1);
		}
		if (flag)
			return (i + 1);
		if (chk_size == -1)
			chk_size = size;
		if (chk_size != size || size == 1)
			return (i + 1);
	}
	g_row = size - 1;
	return (0);
}

int		read_map(int fd, int temp)
{
	int		rd_suc;
	char	c;

	if (!(rd_suc = read(fd, &c, 1)))
		return (1);
	if (!(g_symbol = (char*)malloc(2)))
		return (1);
	g_free++;
	if (read_symbol(fd, rd_suc, c, 1))
		return (1);
	if (ft_strlen(g_symbol) < 4)
		return (1);
	get_symbols();
	if (symbol_chk(g_symbol) || !(g_col = count_col(g_symbol)))
		return (1);
	if (!(g_map = (char**)malloc(sizeof(char*) * g_col)) && g_free++)
		return (1);
	temp = read_map_sub(fd, 1, 1, -1);
	if (temp)
	{
		g_col = temp - 1;
		return (1);
	}
	return (0);
}
