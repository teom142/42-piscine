#include "bsq.h"

extern char	*g_symbol;
//extern char	**g_map;
extern char	g_empty;
extern char	g_obstacle;
extern char	g_fill;
extern unsigned int g_col;
char	*g_temp;

void	get_symbols()
{
	unsigned int sym_len;

	sym_len = ft_strlen(g_symbol);
	g_fill = g_symbol[sym_len - 1];
	g_obstacle = g_symbol[sym_len - 2];
	g_empty = g_symbol[sym_len - 3];
	g_symbol[sym_len - 3] = 0;
}

void    read_map_sub(char *str, char c, unsigned int size)
{
	ft_strcpy(g_temp, str);
	free(str);
	*str = 0;
	str = (char*)malloc(size + 2);
	ft_strcpy(str, g_temp);
	ft_charcat(str, c);
	free(g_temp);
	*g_temp = 0;
}
#include <stdio.h>
void	read_map(int fd, char **map)
{
	int	rd_suc;
	unsigned int size;
	char	c;
	unsigned int i;

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
			g_temp = (char*)malloc(size + 1);
			read_map_sub(g_symbol, c, size);
			rd_suc = read(fd, &c, 1);
			size++;
		}
		get_symbols();
		g_col = count_col(g_symbol);
		//printf("%c %c %c %u\n",g_empty, g_obstacle, g_fill, g_col);
		if(!(map = (char**)malloc(sizeof(char*) * g_col)))
			exit(1);
		i = 0;
		printf("plz");
		while (i < g_col)
		{
			size = 1;
			if(!(map[i] = (char*)malloc(size + 1)))
				exit(1);
			map[i][0] = 0;
			rd_suc = read(fd, &c, 1);
			while (c != '\n')
			{
				g_temp = (char*)malloc(size + 1);
				read_map_sub(map[i], c, size);
				rd_suc = read(fd, &c, 1);
				size++;
			}
			i++;
		}
		disp_map(map, g_col);
	}
	close(fd);
}
