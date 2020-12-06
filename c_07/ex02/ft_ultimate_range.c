/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:45:11 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 10:23:06 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int *temp;

	if (min >= max)
		return (0);
	len = max - min;
	*range = (int*)malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	temp = *range;
	while (min < max)
	{
		*temp = min;
		min++;
		temp++;
	}
	return (len);
}
