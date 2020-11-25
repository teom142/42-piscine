/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:19:59 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 16:20:41 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		it_is_uppercase(char c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int		ft_str_is_uppercase(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_uppercase(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
