/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:33:21 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 05:17:23 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_index(char *base, char c)
{
	int index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int		base_exec_len(char *base)
{
	int len;
	int base_over[256];

	len = 0;
	while (len < 256)
	{
		base_over[len] = 0;
		len++;
	}
	len = 0;
	while (base[len])
	{
		if (base_over[(int)base[len]] ||
				base[len] == '+' ||
				base[len] == '-' ||
				base[len] <= ' ')
			return (0);
		base_over[(int)base[len]] = 1;
		len++;
	}
	return (len);
}

int		ft_atoi_base(char *str, char *base)
{
	int		minus_num;
	int		index_c;
	int		base_len;
	int		ans_num;

	base_len = base_exec_len(base);
	if (base_len <= 1)
		return (0);
	minus_num = 1;
	while (*str <= ' ')
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			minus_num *= -1;
	ans_num = 0;
	while (*str)
	{
		index_c = base_index(base, *(str++));
		if (index_c != -1)
		{
			ans_num *= base_len;
			ans_num += (minus_num * index_c);
		}
	}
	return (ans_num);
}
