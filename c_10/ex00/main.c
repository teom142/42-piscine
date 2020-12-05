#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	char	c;
	int	fd;
	int	rd_suc;

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_putstr("Cannot read file.\n");
		else
		{
			rd_suc = read(fd, &c, 1);
			while (rd_suc && c != '\n')
			{
				write(1, &c, 1);
				rd_suc = read(fd, &c, 1);
			}
			close(fd);
		}
	}
	return (0);
}
