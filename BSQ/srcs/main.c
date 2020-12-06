#include "bsq.h"

unsigned int	g_size;
char		*g_symbol;

unsigned int	get_size(int fd, char *argv)
{
	char		c;
	int		rd_suc;
	unsigned int	cnt;

	fd = open(argv, O_RDONLY);
	rd_suc = read(fd, &c, 1);
	cnt = 1;
	while (rd_suc)
	{
		rd_suc = read(fd, &c, 1);
		cnt++;
	}
	close(fd);
	return (cnt);
}

void	bsq(char *argv)
{
	int	fd;
	char	*map;
	int	rd_suc;
	char	c;

	g_size = get_size(fd, argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_putstr(ERR_MSG);
	else
	{
		rd_suc = read(fd, &c, 1);
		g_symbol = (char*)malloc(5);
		while (rd_suc && c != '\n')
		{
			ft_charcat(g_symbol, c);
			rd_suc = read(fd, &c, 1);
		}
		*g_symbol = 0;
		ft_putstr(g_symbol);
		while (rd_suc)
		{
			map = (char*)malloc(g_size + 1);
			rd_suc = read(fd, &c, 1);
			ft_charcat(map, c);
		}
		close(fd);
	}
}


int	main(int argc, char *argv[])
{
	if (argc == 2)
		bsq(argv[1]);
}
