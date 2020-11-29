/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:47:04 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 05:51:43 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int ret;

	ret = 1;
	if (power == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (power > 0)
	{
		ret *= nb;
		power--;
	}
	return (ret);
}
