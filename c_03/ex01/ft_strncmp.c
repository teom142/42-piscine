/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:42:18 by teom              #+#    #+#             */
/*   Updated: 2020/11/25 15:06:00 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if (s1[index] > s2[index])
		{
			return (1);
		}
		else if (s1[index] < s2[index])
		{
			return (-1);
		}
		index++;
	}
	return (0);
}
