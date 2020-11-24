int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int index;

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
