/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:15:27 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:57:41 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char			*g_default_dict = "dictionary/numbers.dict";
unsigned int	g_size;

unsigned int	get_size(int fd)
{
	char			c;
	int				rd_suc;
	unsigned int	cnt;

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

void			get_line(int fd, char *argv)
{
	char			c;
	int				rd_suc;
	char			*line;

	fd = open(g_default_dict, O_RDONLY);
	rd_suc = read(fd, &c, 1);
	while (rd_suc)
	{
		line = (char*)malloc(g_size);
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
		line[0] = 0;
		rd_suc = read(fd, &c, 1);
		free(line);
	}
	close(fd);
}

void			rush02(char *argv)
{
	int		fd;
	char	*err;

	fd = open(g_default_dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	else
	{
		if (!(err = (char*)malloc(g_size)))
		{
			print_error();
			return ;
		}
		get_line(fd, argv);
	}
}

int				main(int argc, char *argv[])
{
	int				fd;
	unsigned int	max_num;

	fd = open(g_default_dict, O_RDONLY);
	g_size = get_size(fd);
	max_num = find_max_num(g_default_dict, g_size);
	if (argc == 2)
	{
		if (var_check(argv[1]))
			return (0);
		if (ft_strlen(argv[1]) > max_num + 3)
			write(1, "Dict Error\n", 11);
		else
			print_thou(argv[1]);
	}
	else if (argc == 3)
	{
		if (var_check(argv[2]))
			return (0);
		g_default_dict = argv[1];
		fd = open(g_default_dict, g_size);
		max_num = find_max_num(g_default_dict, g_size);
		if (ft_strlen(argv[2]) > max_num + 2)
			write(1, "Dict Error\n", 11);
		else
			print_thou(argv[2]);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
