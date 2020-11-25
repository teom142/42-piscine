/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:42:52 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 10:43:11 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	char *ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == *to_find)
		{
			ptr = str;
			while (*to_find)
			{
				if (*str != *to_find)
				{
					return (0);
				}
				++to_find;
				++str;
			}
		}
		++str;
	}
	return (ptr);
}
