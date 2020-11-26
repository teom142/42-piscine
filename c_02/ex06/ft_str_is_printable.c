/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:21:04 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 16:21:05 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		it_is_printable(char c)
{
	if (' ' <= c && c <= '~')
	{
		return (1);
	}
	return (0);
}

int		ft_str_is_printable(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_printable(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
