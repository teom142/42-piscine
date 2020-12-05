#include "rush02.h"

void	get_line(int fd, char *argv)
{
	char	c;
	int	rd_suc;
	char	*line;

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
		if (chk_number(argv, line))
		{
			ft_putline(line);
		}
		rd_suc = read(fd, &c, 1);
		free(line);
	}
	close(fd);
}

void	rush02(char *argv)
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
	if (argc == 2)
		rush02(argv[1]);
	/*
	else if(argc == 3)
	rush02(argv[1]);
	rush02(argv[2]);
	rush02(argv[3]);
	*/
	return (0);
}
