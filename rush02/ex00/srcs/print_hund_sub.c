/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hund_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:33:40 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:35:22 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	rush02_with_space(char *str)
{
	write(1, " ", 1);
	rush02(str);
}

void	print_init(char *hund)
{
	rush02(hund);
	rush02_with_space("100");
}

void	ft_charcat_3(char *hund, char *ten, char *one, char *str)
{
	ft_charcat(hund, str[0]);
	ft_charcat(ten, str[1]);
	ft_charcat(one, str[2]);
}
