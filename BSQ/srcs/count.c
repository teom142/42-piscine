/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:09:35 by teom              #+#    #+#             */
/*   Updated: 2020/12/07 20:26:31 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

unsigned int	get_sym_size(char *argv)
{
	unsigned int	ret;
	int				fd;
	char			c;
	int				rd_suc;

	fd = open(argv, O_RDONLY);
	rd_suc = read(fd, &c, 1);
	ret = 1;
	while (rd_suc && c != '\n')
	{
		rd_suc = read(fd, &c, 1);
		ret++;
	}
	return (ret);
}

unsigned int	count_col(char *symbol)
{
	unsigned int	ret;

	ret = 0;
	while (*symbol >= '0' && *symbol <= '9')
	{
		ret *= 10;
		ret += (unsigned int)*symbol - '0';
		symbol++;
	}
	return (ret);
}
