#include "bsq.h"

extern char	*g_symbol;
extern char	**g_map;
extern char	g_empty;
extern char	g_obstacle;
extern char	g_fill;
extern int g_col;
extern int g_row;

void	get_symbols()
{
	unsigned int sym_len;

	sym_len = ft_strlen(g_symbol);
	g_fill = g_symbol[sym_len - 1];
	g_obstacle = g_symbol[sym_len - 2];
	g_empty = g_symbol[sym_len - 3];
	g_symbol[sym_len - 3] = 0;
}

char	*expand_str(char *str, int size)
{
	char *ret;

	if (!(ret = (char*)malloc(size + 2)))
		exit(1);
	ft_strcpy(ret, str);
	free(str);
	return (ret);
}

void	read_map_sub(int fd, int rd_suc, char c)
{
	int	i;
	int	size;

	i = 0;
	while (i < g_col)
	{
		size = 1;
		if (!(g_map[i] = (char*)malloc(size + 1)))
			exit(1);
		rd_suc = read(fd, &c, 1);
		while (rd_suc && c != '\n')
		{
			g_map[i][size - 1] = c;
			g_map[i][size] = 0;
			g_map[i] = expand_str(g_map[i], size);
			rd_suc = read(fd, &c, 1);
			size++;
		}
		i++;
	}
	g_row = size - 1;
}
		
void	read_map(int fd)
{
	int	rd_suc;
	int size;
	char	c;

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
		if(!(g_map = (char**)malloc(sizeof(char*) * g_col)))
			exit(1);
		read_map_sub(fd, size, c);
	}
}
