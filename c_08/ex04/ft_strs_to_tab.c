/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:15:49 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 11:15:51 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void					str_cpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = 0;
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*retu;
	int				i;

	retu = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!retu)
		return (0);
	i = 0;
	while (i < ac)
	{
		retu[i].size = str_len(av[i]);
		retu[i].str = (char*)malloc(retu[i].size + 1);
		retu[i].copy = (char*)malloc(retu[i].size + 1);
		str_cpy(retu[i].str, av[i]);
		str_cpy(retu[i].copy, av[i]);
		i++;
	}
	retu[i].str = 0;
	return (retu);
}
