/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:26:34 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 16:54:55 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		it_is_alpha(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int		ft_str_is_alpha(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_alpha(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
