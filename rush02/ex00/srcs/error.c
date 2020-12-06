/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:16:13 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:52:33 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned int	g_max_num;

void			only_num(char *line)
{
	while (*line >= '0' && *line <= '9')
		line++;
	*line = 0;
}

unsigned int	find_max_num(char *dict, unsigned int max_size)
{
	int					fd;
	char				c;
	int					rd_suc;
	char				*line;

	fd = open(dict, O_RDONLY);
	rd_suc = read(fd, &c, 1);
	g_max_num = 0;
	while (rd_suc)
	{
		line = (char*)malloc(max_size);
		ft_charcat(line, c);
		while (rd_suc && c != '\n')
		{
			rd_suc = read(fd, &c, 1);
			ft_charcat(line, c);
		}
		only_num(line);
		if (g_max_num < ft_strlen(line))
			g_max_num = ft_strlen(line);
		rd_suc = read(fd, &c, 1);
		free(line);
	}
	close(fd);
	return (g_max_num);
}

void			print_error(void)
{
	write(1, "error", 5);
	write(1, "\n", 1);
}

int				var_check(char *var)
{
	int		n;

	n = 0;
	while (var[n] != '\0')
	{
		if (var[n] < '0' || '9' < var[n])
		{
			print_error();
			return (1);
		}
		n++;
	}
	return (0);
}
