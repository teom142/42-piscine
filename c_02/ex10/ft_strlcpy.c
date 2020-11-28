/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:22:58 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 20:46:13 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		index;

	index = 0;
	while (src[index] && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	while (src[index])
	{
		index++;
	}
	return (index);
}
