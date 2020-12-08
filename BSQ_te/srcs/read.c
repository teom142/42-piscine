#include "bsq.h"

extern char	*g_symbol;
//extern char	**g_map;
extern char	g_empty;
extern char	g_obstacle;
extern char	g_fill;
extern unsigned int g_col;

void	get_symbols()
{
	unsigned int sym_len;

	sym_len = ft_strlen(g_symbol);
	g_fill = g_symbol[sym_len - 1];
	g_obstacle = g_symbol[sym_len - 2];
	g_empty = g_symbol[sym_len - 3];
	g_symbol[sym_len - 3] = 0;
}

char	*expand_str(char *str, unsigned int size)
{
	char *ret;

	if (!(ret = (char*)malloc(size + 2)))
		exit(1);
	ft_strcpy(ret, str);
	free(str);
	return (ret);
}
#include <stdio.h>
void	read_map_sub(int fd, char **map, int rd_suc, char c)
{
	unsigned int	i;
	unsigned int	size;

	if(!(map = (char**)malloc(sizeof(char*) * g_col)))
		exit (1);
	i = 0;
	while (i < g_col)
	{
		size = 1;
		if (!(map[i] = (char*)malloc(size + 1)))
			exit(1);
		printf("%c",c);
		rd_suc = read(fd, &c, 1);
		while (rd_suc && c != '\n')
		{
			map[i][size - 1] = c;
			map[i][size] = 0;
			map[i] = expand_str(map[i], size);
			rd_suc = read(fd, &c, 1);
			size++;
		}
		i++;
	}
}
		
void	read_map(int fd, char **map)
{
	int	rd_suc;
	unsigned int size;
	char	c;
//	unsigned int i;

	size = 1;
	if (fd == -1)
		ft_putstr(ERR_MSG);
	else
	{
		rd_suc = read(fd, &c, 1);
		if (!(g_symbol = (char*)malloc(size + 1)))
				exit(1);
		while (rd_suc && c != '\n')
		{
			g_symbol[size - 1] = c;
			g_symbol[size] = 0;
			g_symbol = expand_str(g_symbol, size);
			rd_suc = read(fd, &c, 1);
			size++;
		}
		get_symbols();
		g_col = count_col(g_symbol);
		//if(!(map = (char**)malloc(sizeof(char*) * g_col)))
		//	exit(1);
		read_map_sub(fd, map, rd_suc, c);
		/*
		i = 0;
		while (i < g_col)
		{
			size = 1;
			if(!(map[i] = (char*)malloc(size + 1)))
				exit(1);
			rd_suc = read(fd, &c, 1);
			while (c != '\n' && rd_suc)
			{
				map[i][size - 1] = c;
				map[i][size] = 0;
				map[i] = expand_str(map[i], size);
				rd_suc = read(fd, &c, 1);
				size++;
			}
			i++;
		}*/
		disp_map(map, g_col);
	}
	close(fd);
}
