/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:08:45 by teom              #+#    #+#             */
/*   Updated: 2020/12/09 19:47:44 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern char		g_empty;
extern char		g_obstacle;
extern char		g_fill;

int		symbol_chk(char *symbol)
{
	int		i;

	i = -1;
	while (symbol[++i])
	{
		if (symbol[i] < 32 || 126 < symbol[i])
			return (1);
	}
	if (g_empty == g_obstacle || g_empty == g_fill || g_obstacle == g_fill)
		return (1);
	return (0);
}
