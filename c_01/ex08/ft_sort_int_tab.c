void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;
	
	i = size;
	while (i > 0)
	{
		j = 0;
		while (j < i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}
