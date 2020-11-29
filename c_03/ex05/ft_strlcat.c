/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:43:26 by teom              #+#    #+#             */
/*   Updated: 2020/11/29 11:52:10 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;
	unsigned int	src_len;

	index = 0;
	dest_len = str_len(dest);
	src_len = str_len(src);
	while (*dest)
	{
		dest++;
		index++;
	}
	while (*src && index + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		index++;
	}
	*dest = 0;
	if (dest_len > size)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
