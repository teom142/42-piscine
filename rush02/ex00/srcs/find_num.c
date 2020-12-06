/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:19:28 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:26:37 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

void		thou_power(int n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)malloc(n * 3 + 2);
	ret[0] = 0;
	ft_strcat(ret, "1");
	while (i < n)
	{
		ft_strcat(ret, "000");
		i++;
	}
	if (n > 0)
	{
		write(1, " ", 1);
		rush02(ret);
	}
	free(ret);
}

int			chk_thou(char *str)
{
	if (str[0] != '0')
		return (3);
	else
	{
		if (str[1] != '0')
			return (2);
		else if (str[2] != '0')
			return (1);
	}
	return (0);
}

void		print_thou(char *str)
{
	int		thou;
	int		index;

	thou = (int)((ft_strlen(str) - 1) / 3);
	index = (int)(ft_strlen(str) % 3);
	if (index == 0)
		index += 3;
	print_hund(str, index);
	if (thou > 0)
		thou_power(thou);
	thou--;
	while (thou > -1)
	{
		if (chk_thou(str + index))
		{
			if (chk_thou(str + index) == 3)
				write(1, " ", 1);
			print_hund(str + index, 3);
			if (thou > 0)
				thou_power(thou);
		}
		thou--;
		index += 3;
	}
}
