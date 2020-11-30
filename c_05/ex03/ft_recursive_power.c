/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:52:12 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 15:56:41 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (power > 1)
		nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
