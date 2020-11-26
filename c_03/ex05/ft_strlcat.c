/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:43:26 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 10:44:09 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (*dest && index < size)
	{
		dest++;
		index++;
	}
	while (*src && index < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		index++;
	}
	if (index < size)
	{
		*dest = 0;
	}
	return (index);
}
