/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:55 by teom              #+#    #+#             */
/*   Updated: 2020/11/30 18:35:56 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 < ' ' || *s2 < ' ')
			return (0);
		if (*s1 > *s2)
			return (1);
		else if (*s2 > *s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

void	sort_argv(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = argc - 1;
	while (i > 1)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]))
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	sort_argv(argc, argv);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
