#include "rush02.h"

void	get_line(int fd, char **argv)
{
	char	c;
	int	rd_suc;
	char	*line;
	int	print_suc;

	print_suc = 1;
	rd_suc = read(fd, &c, 1);
	while (rd_suc)
	{
		line = (char*)malloc(51);
		ft_charcat(line, c);
		while (rd_suc && c != '\n')
		{
			rd_suc = read(fd, &c, 1);
			ft_charcat(line, c);
		}
		if (chk_number(argv[1], line))
		{
			ft_putline(line);
			print_suc = 0;
		}
		rd_suc = read(fd, &c, 1);
		free(line);
	}
	close(fd);
}

void	rush02(char **argv)
{
	int	fd;

	fd = open(DEFAULT_DICT_FILE, O_RDONLY);
	if (fd == -1)
		write(1, "Dict Error\n", 11);
	else
	{
		get_line(fd, argv);
	}

}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "error", 5);
	rush02(argv);
	return (0);
}
