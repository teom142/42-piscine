/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:46:11 by teom              #+#    #+#             */
/*   Updated: 2020/12/02 16:35:18 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strcat(char *dest, char *src)
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
	return (dest);
}

char			*ft_strjoin(int size, char **strs, char *sep)
{
	int				index;
	char			*ret;
	char			*ret_re;
	unsigned int	strs_len;

	index = 0;
	strs_len = 0;
	while (index < size)
		strs_len += ft_strlen(strs[index++]);
	ret = (char*)malloc(strs_len + (size - 1) * ft_strlen(sep));
	*ret = 0;
	ret_re = ft_strcat(ret, strs[0]);
	index = 1;
	while (index < size)
	{
		ret_re = ft_strcat(ret_re, sep);
		ret_re = ft_strcat(ret_re, strs[index]);
		index++;
	}
	return (ret);
}
