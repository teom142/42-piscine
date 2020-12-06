/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:22:39 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 10:22:42 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*retu;

	len = 0;
	while (src[len])
		len++;
	retu = (char*)malloc(len);
	len = 0;
	while (src[len])
	{
		retu[len] = src[len];
		len++;
	}
	retu[len] = 0;
	return (retu);
}
