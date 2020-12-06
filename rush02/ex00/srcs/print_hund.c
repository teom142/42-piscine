/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hund.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:14:43 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:38:34 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		hund_with_3(char *str)
{
	char	*hund;
	char	*ten;
	char	*one;

	hund = (char*)malloc(1);
	ten = (char*)malloc(2);
	one = (char*)malloc(1);
	hund[0] = 0;
	ten[0] = 0;
	one[0] = 0;
	ft_charcat_3(hund, ten, one, str);
	if (ten[0] == '1')
		ft_charcat(ten, str[2]);
	else
		ft_strcat(ten, "0");
	if (hund[0] != '0')
		print_init(hund);
	if (ten[0] != '0')
		rush02_with_space(ten);
	if (one[0] != '0' && ten[0] != '1')
		rush02_with_space(one);
	free(hund);
	free(ten);
	free(one);
}

void		hund_with_2(char *str)
{
	char	*ten;
	char	*one;

	ten = (char*)malloc(2);
	one = (char*)malloc(1);
	ten[0] = str[0];
	if (*ten == '1')
		ft_charcat(ten, str[1]);
	else
		ft_charcat(ten, '0');
	one[0] = str[1];
	rush02(ten);
	if (one[0] != '0' && ten[0] != '1')
		rush02_with_space(one);
	free(ten);
	free(one);
}

void		print_hund(char *str, int size)
{
	char	*one;

	if (size == 3)
	{
		hund_with_3(str);
	}
	if (size == 2)
	{
		hund_with_2(str);
	}
	if (size == 1)
	{
		one = (char*)malloc(1);
		one[0] = str[0];
		rush02(one);
		free(one);
	}
}
